++++[>++++[>+++<-]<-]    Write the ASCII value of '0' (48 / 0x30) to cell(2)
,>,>                     Read two numbers from stdin into cell(0) and cell(1)
[<-<->>-]                Subtract 48 from both cell(0) and cell(1) to convert from ASCII to integer
<<                       Move to cell(0) for the multiplication loop
[                        Start multiplication loop (cell(0) will be multiplied by cell(1))
    >                    Move to cell(1)
    [>+>+<<-]            Move value from cell(1) to cell(2) and cell(3) (double addition)
    >>                   Move to cell(3)
    [<<+>>-]             Move value from cell(3) back to cell(1)
    <<<-                 Decrement cell(0) and repeat the loop until cell(0) is zero
]
>[-]<                    Clear cell(1) (set to 0), which will now be used as a counter
++++[>++++[>+++<-]<-]    Add 48 to cell(2) to convert the result back to ASCII ('0' + result)
>>.                      Move to cell(2) and print the result (which is now an ASCII character)
