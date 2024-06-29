# trie

It's a simple compact radix trie to hold documents.
here is a representation of such trie:

```
) ( ) ): [ 22:1 ]
( ( ( ): [ 22:1 ]
very ( very ): [ 22:2 ]
g .
    ood ( good ): [ 22:1 ]
    athering ( gathering ): [ 22:1 ]
keep ( keep ): [ 22:1 ]
p .
    otential ( potential ): [ 22:1 ]
    ieces ( pieces ): [ 22:1 ]
    e .
        aceful ( peaceful ): [ 22:1 ]
        ople ( people ): [ 22:1 ]
    r .
        e .
            sent ( present ): [ 22:1 ]
            y ( prey ): [ 22:1 ]
        o .
            claiming ( proclaiming ): [ 22:1 ]
            blem ( problem ): [ 22:2 ]
    lace ( place ): [ 22:1 ]
    a .
        tch ( patch ): [ 22:1 ]
        rticularly ( particularly ): [ 22:1 ]
you ( you ): [ 22:6 ]
u .
    s ( us ): [ 22:1 ]
    n .
        less ( unless ): [ 22:1 ]
        derstand ( understand ): [ 22:1 ]
h .
    a ( ha ): [ 22:2 ]
        ve ( have ): [ 22:3 ]
        s ( has ): [ 22:1 ]
    u .
        man ( human ): [ 22:2 ]
        n .
            dreds ( hundreds ): [ 22:1 ]
            ting ( hunting ): [ 22:1 ]
    is ( his ): [ 22:1 ]
    o .
        me ( home ): [ 22:2 ]
        wever ( however ): [ 22:1 ]
    elped ( helped ): [ 22:1 ]
w .
    i .
        nd ( wind ): [ 22:1 ]
        thin ( within ): [ 22:1 ]
    a .
        nt ( want ): [ 22:3 ]
            s ( wants ): [ 22:3 ]
        rrior ( warrior ): [ 22:1 ]
    ren ( wren ): [ 22:2 ]
    h .
        at ( what ): [ 22:2 ]
            ever ( whatever ): [ 22:1 ]
        ich ( which ): [ 22:1 ]
        e .
            re ( where ): [ 22:1 ]
            n ( when ): [ 22:2 ]
    orth ( worth ): [ 22:1 ]
l .
    obsters ( lobsters ): [ 22:6 ]
    arge ( large ): [ 22:1 ]
    i .
        ke ( like ): [ 22:1 ]
        v .
            e ( live ): [ 22:2 ]
            ing ( living ): [ 22:1 ]
 (  ): [ 22:4 ]
e .
    xample ( example ): [ 22:2 ]
    dible ( edible ): [ 22:1 ]
    ngage ( engage ): [ 22:1 ]
    a .
        rs ( ears ): [ 22:1 ]
        sily ( easily ): [ 22:1 ]
        ting ( eating ): [ 22:2 ]
? ( ? ): [ 22:2 ]
 (  ): [ 22:2 ]
n .
    e .
        st ( nest ): [ 22:1 ]
        ed ( need ): [ 22:1 ]
        wly ( newly ): [ 22:1 ]
        rvous ( nervous ): [ 22:1 ]
        ur .
            al ( neural ): [ 22:1 ]
            ons ( neurons ): [ 22:1 ]
    orth ( north ): [ 22:2 ]
m .
    ight ( might ): [ 22:1 ]
    u .
        sical ( musical ): [ 22:1 ]
        ch ( much ): [ 22:1 ]
    a .
        tes ( mates ): [ 22:1 ]
        ke ( make ): [ 22:1 ]
        p ( map ): [ 22:1 ]
        gic ( magic ): [ 22:1 ]
        ny ( many ): [ 22:1 ]
    o .
        re ( more ): [ 22:2 ]
        st ( most ): [ 22:1 ]
f .
    a .
        mily ( family ): [ 22:1 ]
        r ( far ): [ 22:1 ]
    loor ( floor ): [ 22:1 ]
    unction ( function ): [ 22:1 ]
    e .
        isty ( feisty ): [ 22:1 ]
        rocious ( ferocious ): [ 22:1 ]
        eling ( feeling ): [ 22:1 ]
    o .
        od ( food ): [ 22:1 ]
        r ( for ): [ 22:5 ]
    rom ( from ): [ 22:2 ]
d .
    o .
        mination ( domination ): [ 22:1 ]
        wn ( down ): [ 22:2 ]
        n ( don ): [ 22:1 ]
    e .
        licious ( delicious ): [ 22:1 ]
        ath ( death ): [ 22:1 ]
    is .
        putes ( disputes ): [ 22:1 ]
        tance ( distance ): [ 22:1 ]
 (  ): [ 22:4 ]
r .
    a .
        nge ( range ): [ 22:1 ]
        i .
            n ( rain ): [ 22:1 ]
                s ( rains ): [ 22:1 ]
            se ( raise ): [ 22:1 ]
    efuse ( refuse ): [ 22:1 ]
- ( - ): [ 22:1 ]
o .
    ther ( other ): [ 22:1 ]
    ne ( one ): [ 22:1 ]
    c .
        cupy ( occupy ): [ 22:1 ]
        ean ( ocean ): [ 22:2 ]
    bservable ( observable ): [ 22:1 ]
    ften ( often ): [ 22:1 ]
b .
    i .
        rd ( bird ): [ 22:1 ]
        ts ( bits ): [ 22:1 ]
    r .
        illiantly ( brilliantly ): [ 22:1 ]
        ain ( brain ): [ 22:2 ]
    ot .
        h ( both ): [ 22:1 ]
        tom ( bottom ): [ 22:1 ]
    e .
        ings ( beings ): [ 22:1 ]
        en ( been ): [ 22:1 ]
        autiful ( beautiful ): [ 22:1 ]
        haviour ( behaviour ): [ 22:1 ]
        cause ( because ): [ 22:1 ]
    uild ( build ): [ 22:1 ]
    ase ( base ): [ 22:1 ]
 (  ): [ 22:2 ]
i .
    f ( if ): [ 22:3 ]
    t ( it ): [ 22:1 ]
    s ( is ): [ 22:3 ]
    n ( in ): [ 22:5 ]
        cluding ( including ): [ 22:1 ]
        sect ( insect ): [ 22:1 ]
        teresting ( interesting ): [ 22:1 ]
t ( t ): [ 22:1 ]
    ime ( time ): [ 22:1 ]
    wo ( two ): [ 22:1 ]
    ake ( take ): [ 22:1 ]
    erritor .
        ial ( territorial ): [ 22:1 ]
        y ( territory ): [ 22:1 ]
    oo ( too ): [ 22:1 ]
    rying ( trying ): [ 22:1 ]
    h .
        i .
            nk ( think ): [ 22:2 ]
            s ( this ): [ 22:4 ]
        a .
            n ( than ): [ 22:1 ]
            t ( that ): [ 22:1 ]
        e ( the ): [ 22:18 ]
            re ( there ): [ 22:4 ]
            m ( them ): [ 22:1 ]
            se ( these ): [ 22:1 ]
            ir ( their ): [ 22:2 ]
            y ( they ): [ 22:6 ]
a ( a ): [ 22:12 ]
    merica ( america ): [ 22:1 ]
    b .
        le ( able ): [ 22:1 ]
        o .
            ve ( above ): [ 22:1 ]
            ut ( about ): [ 22:1 ]
    way ( away ): [ 22:1 ]
    l .
        l ( all ): [ 22:1 ]
        so ( also ): [ 22:1 ]
    r .
        rived ( arrived ): [ 22:1 ]
        ound ( around ): [ 22:1 ]
    ttractive ( attractive ): [ 22:1 ]
    ccurately ( accurately ): [ 22:1 ]
    n .
        imals ( animals ): [ 22:1 ]
        d ( and ): [ 22:14 ]
, ( , ): [ 22:26 ]
c .
    haos ( chaos ): [ 22:1 ]
    ircuitry ( circuitry ): [ 22:1 ]
    ells ( cells ): [ 22:1 ]
    o .
        n .
            vince ( convince ): [ 22:1 ]
            tinual ( continual ): [ 22:1 ]
            sidering ( considering ): [ 22:1 ]
        m .
            mon ( common ): [ 22:2 ]
            p .
                etitors ( competitors ): [ 22:1 ]
                lex ( complex ): [ 22:1 ]
                aratively ( comparatively ): [ 22:1 ]
            e ( come ): [ 22:1 ]
    r .
        ies ( cries ): [ 22:1 ]
        abby ( crabby ): [ 22:1 ]
        ustaceans ( crustaceans ): [ 22:1 ]
        owded ( crowded ): [ 22:1 ]
        eatures ( creatures ): [ 22:1 ]
    lose ( close ): [ 22:1 ]
    a .
        lls ( calls ): [ 22:1 ]
        rnage ( carnage ): [ 22:1 ]
        n ( can ): [ 22:1 ]
. ( . ): [ 22:19 ]
s .
    mall ( small ): [ 22:2 ]
    a .
        nd ( sand ): [ 22:1 ]
        me ( same ): [ 22:3 ]
    i .
        n .
            g ( sing ): [ 22:1 ]
            ce ( since ): [ 22:1 ]
        ren ( siren ): [ 22:1 ]
        mple ( simple ): [ 22:1 ]
    tr .
        ay ( stray ): [ 22:1 ]
        ucture ( structure ): [ 22:1 ]
    ystem ( system ): [ 22:1 ]
    c .
        avenge ( scavenge ): [ 22:1 ]
        ientists ( scientists ): [ 22:1 ]
    heltered ( sheltered ): [ 22:1 ]
    o ( so ): [ 22:1 ]
        ng .
            s ( songs ): [ 22:1 ]
            bird ( songbird ): [ 22:1 ]
                s ( songbirds ): [ 22:1 ]
        mewhere ( somewhere ): [ 22:1 ]
        vereignty ( sovereignty ): [ 22:1 ]
    p .
        ace ( space ): [ 22:1 ]
        ring ( spring ): [ 22:1 ]
    ecure ( secure ): [ 22:1 ]
```

nodes with `.` are non leaf nodes.
nodes with `() []` are leaf nodes that hold the data:

nodes with `.` are non leaf nodes.
nodes with `() []` are leaf nodes that hold the data:
    1. the term
    2. the documents it exists in
    3. the count in such documents
