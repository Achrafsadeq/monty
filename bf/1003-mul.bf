>>>              # Move to a safer position (starting at cell 3 to avoid out-of-bounds issues)
,                # Read the first digit (in ASCII) into cell(3)
>,               # Read the second digit (in ASCII) into cell(4)
[->+<]           # Subtract 48 (ASCII '0') from the first digit (convert ASCII to integer)
[->+<]           # Subtract 48 (ASCII '0') from the second digit (convert ASCII to integer)
<<<               # Go back to cell(3) (for multiplication loop)
[                # Start the multiplication loop
    >            # Move to cell(4)
    [>+>+<<-]    # Multiply: add cell(4) value to cell(5) and cell(6)
    >>           # Move to cell(6)
    [<<+>>-]     # Move value from cell(6) back to cell(4)
    <<<-         # Decrement cell(3)
]
>[-]<            # Clear cell(4), use it as a temporary counter
++++[>++++[>+++<-]<-] # Add 48 to the result (in cell(5)) to convert to ASCII for printing
>>.              # Print the result (go to cell(5) and print it)
