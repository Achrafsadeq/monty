>,>,<<                 # Read two digits from stdin (in ASCII)
[                      # Loop to subtract 48 from both digits to convert ASCII to integers
    >--------          # Subtract 8 (part 1)
    >--------          # Subtract 8 (part 2)
    <<-                # Decrement loop counter
]
++++++++>              # Add 8 to adjust for ASCII offset and prepare for multiplication
[
    >                  # Move to first digit
    [                  # Loop through first digit
        ->+>+<<        # Multiply: transfer value to create partial products
    ]
    >>                 # Move to second result
    [                  # Loop through second digit
        -<<+>>         # Combine partial products
    ]
    <<<                # Move back to starting position
    -                  # Decrement loop counter
]
<                      # Final adjustment
[
    >>>++++++          # Add 6 to convert result back to ASCII
    <<<-               # Decrement loop counter
]
>>>.                   # Output the result (single digit multiplication result)
