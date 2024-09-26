++++[>++++[>+++<-]<-]   writing ASCII value 48 / 0x30 / '0' into cell(2)
,>,>                    reading two digits into cell(0) and cell(1)
[<-<->>-]               subtract 48 / 0x30 / '0' from cell(0) and cell(1)
<<                      move to cell(0)
[                       start multiplication loop
    >                   move to cell(1)
    [>+>+<<-]           copy value from cell(1) to cell(2) and cell(3)
    >>                  move to cell(3)
    [<<+>>-]            move value from cell(3) back to cell(1)
    <<<-                decrement cell(0)
]
>[-]<                   clear cell(1) (set to 0) to reuse as counter (now in cell 0)
++++[>++++[>+++<-]<-]   add 48 / 0x30 / '0' to cell(2), which contains the result
>>.                     move to cell(2) and print the result
