# Set breakpoints
break main
break docking_module.cpp:48

# Set GDB settings
set print pretty on
set pagination off

# Set GDB aliases
alias l list
alias s step
alias n next
alias c continue
alias bt backtrace

set history save on
set history size unlimited
set history filename ~/.gdb_history