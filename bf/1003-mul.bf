,>>+++ +++[<<-------->>-]   # Read first digit and subtract 48 (ASCII '0') to convert to integer
<,>+++ +++[<-------->-]     # Read second digit and subtract 48 (ASCII '0') to convert to integer
<                           # Move back to the first cell
[<[>>+>+<<<-]               # Start the multiplication loop: copy second value to two locations
>>>                         # Move to the temporary storage cell
[<<<+>>>-]                  # Move value from the temporary storage back to the original
<<-]                        # Decrement first digit and repeat the loop until zero
>>++++++[<++++++++>-]       # Add 48 to the result to convert back to ASCII ('0')
<.                          # Print the result
