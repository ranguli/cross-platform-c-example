project('cross-platform-c-example', 'c',
        default_options: ['warning_level=everything'])

# Compiler flags
add_global_arguments('-Wpedantic', language: 'c')

srcs = files(
  'platforms/windows.c',
  'platforms/posix.c',
  'sleep.c',
  'main.c'
)

# Define executable
executable('example', srcs, include_directories: '.')

