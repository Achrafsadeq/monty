,                # Read the first digit (in ASCII) into cell(0)
>,               # Read the second digit (in ASCII) into cell(1)
[->+<]           # Subtract 48 (ASCII '0') from the first digit to convert to integer
[->+<]           # Subtract 48 (ASCII '0') from the second digit to convert to integer
<<               # Go to cell(0)
[                # Start the multiplication loop
    >            # Move to cell(1)
    [>+>+<<-]    # Multiply: add cell(1) value to cell(2) and cell(3)
    >>           # Go to cell(3)
    [<<+>>-]     # Move value from cell(3) back to cell(1)
    <<<-         # Decrement cell(0)
]
>[-]<            # Clear cell(1), use it as a temporary counter
++++[>++++[>+++<-]<-] # Add 48 to result (in cell(2)) to convert to ASCII for printing
>>.              # Print the result (go to cell(2) and print it)
