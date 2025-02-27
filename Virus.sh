#RUN WITH bash filename.sh

#!/bin/bash

# Disable Ctrl+C (SIGINT), Ctrl+Z (SIGTSTP), and Ctrl+D (EOF) explicitly
trap 'echo "Ctrl+C is disabled!"; sleep 1' SIGINT
trap 'echo "Ctrl+Z is disabled!"; sleep 1' SIGTSTP
trap 'echo "Ctrl+D is disabled!"; sleep 1' SIGQUIT

# Infinite loop to lock the terminal
while true; do
  # Prompt for input without newline
  echo -n "Please type 'Koushambha' to unlock: "
  read input
  
  # Check if the input matches the correct name using single brackets
  if [ "$input" = "Koushambha" ]; then
    echo "Unlocked! You can now continue."
    break
  fi
done
