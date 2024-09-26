 ++++[>++++[>+++<-]<-]   Write the ASCII value of '0' (48 / 0x30) to cell(2)
    ,>,>                    Read two numbers from stdin into cell(0) and cell(1)
    [<-<->>-]               Subtract 48 from both cell(0) and cell(1) to convert from ASCII to integer
    <<                      Move to cell(0) for the multiplication loop
    [                       mulitplication loop
        >                   go to cell(1)
        [>+>+<<-]           move cell(1) to cell(2) and cell(3)
        >>                  go to cell(3)
        [<<+>>-]            move cell(3) back to cell(1)
        <<<-                decrement cell(0)
    ]
    >[-]<                   Clear cell(1) (set to 0), which will now be used as a counter
    ++++[>++++[>+++<-]<-]   Add 48 to cell(2) to convert the result back to ASCII ('0' + result)
    >>.                     print result (go to cell 2 and print)
