#!/afs/cats.ucsc.edu/courses/cmps112-wm/usr/smalltalk/bin/gst -f
"Kevin Cai"
"Trevor Barnes"

execname := '$RCSfile: cmdline.st,v $' =~ '.*: (.*),v.*' at: 1.
nl := Character nl.
queue := SortedCollection new.

debugOpt := false.
compressOpt := false.
printOpt := false.
uncompressFlag := false.

args:=0.

|uncompressTree ExitStatus|

""
Character extend [
   isPrint [
      ^ (Character space < self) & (self <= $~)
   ]
   digits[
         ^ (self asInteger) > 15
         ]
   visible [
        "stdout << (self asInteger)."
      self isPrint ifTrue: [^' ', self asString, ' ']             
                    ifFalse: [ self digits
                        ifTrue:[((self asInteger) = 256)
                            ifTrue:[ ^ 'EOF']ifFalse:[^ 'x',
                                ((self asInteger printStringRadix: 16)
                                copyFrom: 4 )]
                        ] ifFalse:[
                                ^ 'x0',
                                ((self asInteger printStringRadix: 16)
                                copyFrom: 4)]
                        ]
   ]
]

"taken from mackey - data storage"
Object subclass: ZeroArray [
   |theArray|

   ZeroArray class >> new [
      self shouldNotImplement.
   ]

   ZeroArray class >> new: size [
      |result|
      result := super new.
      result init: size.
      ^ result
   ]

   init: size [
      theArray := Array new: size.
   ]

   size [
      ^ theArray size.
   ]

   at: index [
      ^ theArray at: index + 1.
   ]

   at: index put: value [
      ^ theArray at: index + 1 put: value.
   ]

   incr: index [
      (self at: index) isNil
         ifTrue: [ self at: index put: 0].
      self at: index put: (self at: index) + 1.
   ]

   keysAndValuesDo: aBlock [
      (0 to: (self size) - 1) do: [:index |
         aBlock value: index value: (self at: index).
      ]
   ]
]

"taken from mackey - filstream helper"
FileStream extend [
   nl := Character nl.
   catFile [
      |total linenr|
      total := 0.
      [self atEnd not] whileTrue: [
         total := total + 1.
         linenr := self nextLine.
         total asString size to: 5 do: [:skip| stdout << ' '].
         stdout << total << ': ' << linenr << nl.
      ]
   ]
]

ftbl := ZeroArray new: 257.
ftbl at: 256 put:1.
etbl := ZeroArray new: 257.
 
Object subclass: Leaf [
   |char total isleaf|
   
   char [ ^ char ]
   total [ ^ total ]
   isleaf [^ isleaf]
   
   Leaf class >> new [
      self shouldNotImplement
   ]

   Leaf class >> new: aChar total: aTotal [
      |result|
      result := super new.
      result setChar: aChar andTotal: aTotal.      
      ^result
   ]

   setChar: aChar andTotal: aTotal [
      char := aChar.
      total := aTotal.
      isleaf:=true.
   ]

   <= other [
      ^ (total < other total)
      | ((total = other total) & (char <= other char))
   ]

   printBase: aStream [
      ^ aStream << self class << '(' << char << ',' << total
   ]

   printOn: aStream [
      (self printBase: aStream) << ')'.
   ]

   inorder: visitor prefix: string [
      visitor value: char value: string.
   ]
   
   postorder: visitor [
      visitor  value:char value: isleaf.
   ]
]

Leaf subclass: Tree [
   |lft rgt|

   Tree class >> new: aChar total: aTotal [
      self shouldNotImplement
   ]

   Tree class >> new: aChar total: aTotal lft: aLft rgt: aRgt [
      |result|
      result := super new: aChar total: aTotal.
      result assignLft: aLft andRgt: aRgt.
      ^ result
   ]

   assignLft: aLft andRgt: aRgt [
      lft := aLft.
      rgt := aRgt.
      isleaf:=false.
   ]

   lft  [ ^ lft]
   rgt [ ^ rgt]

   printOn: aStream [
      (self printBase: aStream) << ',' << lft << ',' << rgt << ')'.
   ]

   inorder: visitor prefix: string [
      lft inorder: visitor prefix: string, '0'.
      rgt inorder: visitor prefix: string, '1'.
   ]
   
   postorder: visitor[      
      lft postorder: visitor .
      rgt postorder: visitor .  
      visitor value: char value:isleaf.
   ]
]

Object subclass: BitStream [
   |bitIndex byte myStream|
   BitStream class >> new: fileStream [
      |result|
      result := super new.
      result init: fileStream.
      ^result
   ]
   init: fileStream [
      myStream := fileStream.
      bitIndex := 1.
   ]
   nextBit [
      bitIndex = 1 ifTrue: [
         byte := myStream next.
         bitIndex := 9.
      ].
      bitIndex := bitIndex - 1.
      ^byte value bitAt: bitIndex
   ]
   atEnd [
      ^bitIndex = 1 and: [myStream atEnd]
   ]
]

Object subclass: OutBits [
   |bitIndex currentByte myStream|
   OutBits class >> new [
      self shouldNotImplement.
   ]
   OutBits class >> new: fileStream [
      |result|
      result := super new.
      result init: fileStream.
      ^result
   ]
   clearByte [
      bitIndex := 8.
      currentByte := 0.
   ]
   init: fileStream [
      myStream := fileStream.
      self clearByte.
   ]
   flushByte [
         myStream nextPutByte: currentByte.
         self clearByte.

   ]
   writeBit: bit [
      currentByte := currentByte bitAt: bitIndex put: bit.
      bitIndex := bitIndex - 1.
      bitIndex = 0 ifTrue: [
        self flushByte].
   ]
]

|input input2 output args|

"flags for running program"
Smalltalk arguments: '-c -d -t -u'
do: [:flag :option |

    (flag = $c) ifTrue: [
        compressOpt := true.
    ].

    (flag = $d) ifTrue: [
        debugOpt := true.
    ].

    (flag = $t) ifTrue: [
        printOpt := true.
    ].

    (flag = $u) ifTrue: [
        uncompressFlag := true.
    ].

    (option ~= nil) ifTrue: [
     args = 0 

        ifFalse:[
            debugOpt ifTrue:[
                stdout <<'output filename: ' << option << nl.
            ].
            output := FileStream open: option
                       mode: FileStream write.
        ] ifTrue: [
            debugOpt ifTrue:[
                stdout <<'input filename: ' << option << nl.
            ].

            input2 := FileStream open: option
                        mode: FileStream read.
            input := FileStream open: option
                        mode: FileStream read.          
        ].
        args := args + 1.
    ].
].

uncompressFlag ifFalse:[

    [input atEnd not] whileTrue: [
        |order|
        order := input next asInteger.
        ftbl incr: order.
    ].

    ftbl keysAndValuesDo: [:key :total |
        (total notNil and: [total > 0]) ifTrue: [
            queue add: (Leaf new: key total: total).
        ]
    ].

    [queue size >1 ] whileTrue: [
        |lftnode rgtnode|

        lftnode := queue removeFirst.
        rgtnode := queue removeFirst.
        newtree := ( Tree new: (lftnode char)
                      total: (lftnode total) +  (rgtnode total)
                      lft: lftnode rgt: rgtnode).
        queue add: newtree.
    ].
    uncompressTree:=queue removeFirst.

    uncompressTree inorder: [:char :string |
        etbl at: char put: string.
    ] prefix: ''.

    nodetree := ''.
    uncompressTree postorder: [:char :isleaf |

        isleaf  ifFalse:[nodetree:=nodetree,'1'.]
        ifTrue:[
            bin:=''.
            char = 256
            ifTrue:[bin:='000000001']
            ifFalse:[
                char = 0 ifTrue:[bin:='000000000']
                ifFalse:[
                    8 to:1 by: -1 do:[:i|
                        bin := bin,((char bitAt:i)printString).
                    ]
                ].               
            ].
            nodetree:=(nodetree,'0',bin).
        ].
    ].

"Compress File"
compressOpt  ifTrue:[
    output~=nil ifTrue:[
        outBytes := OutBits new: output.    
        1 to: (nodetree size) by: 1 do: [:index |
            bt:= ((nodetree at: index) asInteger) - 48.
            outBytes writeBit: bt.
        ].

        outBytes writeBit: 1.

        [input2 atEnd not] whileTrue: [
            |order2|
            order2 := input2 next asInteger.
            info:= (etbl at: order2). 
            1 to: (info size) by: 1 do: [:index |
                bt:= ((info at: index) asInteger) - 48.
                outBytes writeBit: bt.
            ].
        ].

        eof:= (etbl at: 256).
        1 to: (eof size) by: 1 do: [:index |
            bt:= ((eof at: index) asInteger) - 48.
            outBytes writeBit: bt.
        ].     
        outBytes flushByte.
    ]


    ifFalse:[
        debugOpt ifTrue:[
            stdout << nl << 'compressOpt = '<< compressOpt
                <<' missing file'<< nl.].

            stdout << nodetree << 1.      

            [input2 atEnd not] whileTrue: [
                |order2|
                order2 := input2 next asInteger.
                info:= (etbl at: order2).
                stdout << info. 
            ].
            eof:= (etbl at: 256).
            stdout << eof.
        ].    
    ]. "end of inner -c flag func"
]. "end of outer -u flag false"

"uncompress flag option"
(uncompressFlag) ifTrue:[
    |temp outBytes stk|
    temp := false.

    outBytes := OutBits new: output.  
    stk := OrderedCollection new.
    fileBits := BitStream new: input.
    tConstruct := false.
    newTree := ''.
    leaf := ''.   

    "input file gets read by bit"
    [(fileBits atEnd not) & (temp not)] whileTrue: [

        tchild := fileBits nextBit.
        childinfo := 0.


        "if decoding tree still building, then 
        transform input into a leaf"
        tConstruct ifFalse: [

            tchild = 0 ifTrue: [
                8 to: 1 by: -1 do: [:i|
                    bt:=fileBits nextBit.
                    childinfo:=childinfo bitAt:i put:bt.
                ].

                childinfo = 0 ifTrue: [
                    sbit := fileBits nextBit.
                    sbit = 1 ifTrue:[
                        childinfo := childinfo bitAt: 9 put: 1.
                    ].
                ].
                stk add: (Leaf new: childinfo total: '').
            ].

            "if 2 leaves, build tree"
            tchild = 1 ifTrue:[
                stk size>1 ifTrue:[
                    rgtnode:=stk removeLast.
                    lftnode:=stk removeLast.

                    newtree := (Tree new: -1
                        total: ''
                        lft: lftnode rgt: rgtnode).
                        stk add: newtree.
                ] ifFalse:[
                    tConstruct:=true.
                    newTree:=stk removeLast.
                    leaf:=newTree.

                ].
            ].
        ]

        ifTrue:[       
            leaf isleaf ifTrue:[
                ((leaf char)=256) ifTrue:[
                    temp := true.
                ] ifFalse: [
                    stdout nextPut: (Character value: (leaf char)).
                    leaf := newTree.].

            ] ifFalse: [
                tchild = 0 ifTrue:[
                    leaf := leaf lft.
                    leaf isleaf ifTrue:[
                        temp not ifTrue:[  
                            ((leaf char)=256) ifTrue:[
                                temp:=true.
                            ] ifFalse: [
                                output=nil ifTrue:[

                        stdout nextPut: (Character value: (leaf char)).                        
                                ]
                                ifFalse:[
                                    8 to: 1 by: -1 do: [:index |
                                    bt:= (leaf char) bitAt: index.
                                    outBytes writeBit: bt.
                                    ].
                                ].
                                leaf:=newTree.
                            ].
                        ].
                    ]
                ]

                ifFalse: [    
                    leaf := leaf rgt.

                    leaf isleaf ifTrue: [
                        temp not ifTrue: [
                            ((leaf char) = 256) ifTrue: [
                                temp := true.
                            ] ifFalse:[
                                output=nil ifTrue:[

                        stdout nextPut: (Character value: (leaf char)).

                                ]
                                ifFalse:[
                                    8 to: 1 by: -1 do: [:index |
                                        bt:= (leaf char) bitAt: index.
                                        outBytes writeBit: bt.
                                    ].
                                ].
                            leaf:=newTree.
                            ].
                        ].
                    ]
                ].
            ].
        ].
    ].
]. "end of -u flag option" 

"print -t flag print decoding tree"
printOpt ifTrue:[
    "print decoding tree"
    stdout << nl << 'decoding tree' << nl.
    stdout << uncompressTree << nl << nl.
    "encoding table"
    ""
    stdout << nl << 'encoding table' << nl.
    etbl keysAndValuesDo: [:key :total |
        (total notNil and: [total > 0]) ifTrue: [
            stdout << key asCharacter visible << '       '
                    << (ftbl at: key) << '  ' << total << nl.
            
        ].
    ].
].

"exit file, program end"
input close.

output ~= nil ifTrue: [
    output close.
].

ExitStatus:=0.

debugOpt ifTrue: [
    stdout<< nl << 'Exit Status: ' << ExitStatus << nl.
].
