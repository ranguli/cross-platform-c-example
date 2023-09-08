# cross-platform-c-example

Really barebones implementation of one of the many ways that it is suggested 

This is a simple-as-possible example of an often-recommended way of writing cross-platform C code. The example shows a solution for creating a cross-platform `sleep()`. Windows and POSIX systems define their sleep functions in different headers. On Windows, the function is `Sleep()` with a capital S, and expects the sleep duration to be in milliseconds. On POSIX, the function has a lowercase S (`sleep()`) and expects the sleep duration to be in seconds. The example code is so small that it looks very over-engineered, but it serves as a stand-in for how the approach would be implemented in larger projects. 

## Benefits

There are a few benefits of this approach:
-  No usage of the C preprocessor to solve the problem. 
    - There is no conditonal inclusion of code inside a function. The solution does _not_ require any code that looks like this:
        ```c
        void my_cross_platform_function() {
            #ifdef _WIN32
                // do dome stuff. my existence is decided by a preprocessor
            #endif

            // rest of the code
        }
        ```
    - There is also no conditional inclusion of header files. The solution does _not_ require any code that looks like this:
        ```c
        #ifdef _WIN32
        #include "windows_stuff.h"
        #else
        #include "posix_stuff.h"
        #endif

        void my_cross_platform_function() {
            #ifdef _WIN32
                my_windows_stuff_function() 
            #else
                my_posix_stuff_function() 
            endif
        }
        ```
- All platform-specific code lives its own sub-directory for that platform.
- Utilizes the build system to determine the platform (and therefore what code to build). 

## Implementation

So what does the actual solution look like?

```c

void my_cross_platform_function() {
    platform_function();
}
```

- All platform-specific code is in a `platforms/` directory.
    - For small examples like this, one `.c` file and one `.h` file exist for each platform (`windows.c`, `windows.h`, `posix.c`, `posix.h`).
    - For larger projects, a subdirectory of `platforms/` for each platform would be used (i.e `platforms/windows/io.c`)
    - This makes it clear that **all** other code in the project is cross-platform. All the platform-specific weirdness is contained to `platforms/`. 
- For each platform where platform-specific code is required, a `platform_myfunc()` is created in each platforms source-file. 
- A cross-platform wrapper function is created that makes a call to `platform_myfunc()`, called `myfunc()`.
- At compile time, the build system determines the host platform, and include only the source files from `platforms/` for the host platform.
  ```meson
  # Check if the target system is Windows.
  if host_machine.system() == 'windows'
      sources += 'src/platforms/windows.c'
  else
  ```
- The compiler and linker resolve `platform_myfunc()`, and a cross-platform function called `myfunc()` is available that can be called.
