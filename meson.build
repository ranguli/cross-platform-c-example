project('cross-platform-c-example', 'c', default_options: ['warning_level=everything', 'c_std=c99'])

# Compiler flags
add_global_arguments('-Wpedantic', language: 'c')

sources = files(
    'src/sleep.c',
    'src/main.c'
)

# Check if the target system is Windows.
if host_machine.system() == 'windows'
  sources += 'src/platforms/windows.c'
else
  sources += 'src/platforms/posix.c'
endif

# Define executable
executable('example', sources, include_directories: ['src'])
