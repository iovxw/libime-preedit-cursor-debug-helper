fcitx5 libime input ↔︎ preedit cursor debug helper

```
./dump /path/to/libime/build aahkaa
```

```
=== real cursor 0 : |aahkaa ===
public preedit: |a hao a
forward (virtual cursor -> preedit):
  |aahkaa  v=0  ->  |a hao a
  a|ahkaa  v=1  ->  |a hao a
  aa|hkaa  v=2  ->  a| hao a
  aah|kaa  v=3  ->  a h|ao a
  aahk|aa  v=4  ->  a hao| a
  aahka|a  v=5  ->  a hao| a
  aahkaa|  v=6  ->  a hao a|
reverse (preedit cursor -> input):
  |a hao a  ->  |aahkaa
  a| hao a  ->  aa|hkaa
  a |hao a  ->  aa|hkaa
  a h|ao a  ->  aah|kaa
  a ha|o a  ->  aah|kaa
  a hao| a  ->  aahk|aa
  a hao |a  ->  aahk|aa
  a hao a|  ->  aahkaa|

=== real cursor 1 : a|ahkaa ===
public preedit: _|a hao a
forward (virtual cursor -> preedit):
  |aahkaa  v=0  ->  |_a hao a
  a|ahkaa  v=1  ->  _|a hao a
  aa|hkaa  v=2  ->  _a| hao a
  aah|kaa  v=3  ->  _a h|ao a
  aahk|aa  v=4  ->  _a hao| a
  aahka|a  v=5  ->  _a hao| a
  aahkaa|  v=6  ->  _a hao a|
reverse (preedit cursor -> input):
  |_a hao a  ->  |aahkaa
  _|a hao a  ->  a|ahkaa
  _a| hao a  ->  aa|hkaa
  _a |hao a  ->  aa|hkaa
  _a h|ao a  ->  aah|kaa
  _a ha|o a  ->  aah|kaa
  _a hao| a  ->  aahk|aa
  _a hao |a  ->  aahk|aa
  _a hao a|  ->  aahkaa|

=== real cursor 2 : aa|hkaa ===
public preedit: a| hao a
forward (virtual cursor -> preedit):
  |aahkaa  v=0  ->  |a hao a
  a|ahkaa  v=1  ->  |a hao a
  aa|hkaa  v=2  ->  a| hao a
  aah|kaa  v=3  ->  a h|ao a
  aahk|aa  v=4  ->  a hao| a
  aahka|a  v=5  ->  a hao| a
  aahkaa|  v=6  ->  a hao a|
reverse (preedit cursor -> input):
  |a hao a  ->  |aahkaa
  a| hao a  ->  aa|hkaa
  a |hao a  ->  aa|hkaa
  a h|ao a  ->  aah|kaa
  a ha|o a  ->  aah|kaa
  a hao| a  ->  aahk|aa
  a hao |a  ->  aahk|aa
  a hao a|  ->  aahkaa|

=== real cursor 3 : aah|kaa ===
public preedit: a h|ao a
forward (virtual cursor -> preedit):
  |aahkaa  v=0  ->  |a hao a
  a|ahkaa  v=1  ->  |a hao a
  aa|hkaa  v=2  ->  a| hao a
  aah|kaa  v=3  ->  a h|ao a
  aahk|aa  v=4  ->  a hao| a
  aahka|a  v=5  ->  a hao| a
  aahkaa|  v=6  ->  a hao a|
reverse (preedit cursor -> input):
  |a hao a  ->  |aahkaa
  a| hao a  ->  aa|hkaa
  a |hao a  ->  aa|hkaa
  a h|ao a  ->  aah|kaa
  a ha|o a  ->  aah|kaa
  a hao| a  ->  aahk|aa
  a hao |a  ->  aahk|aa
  a hao a|  ->  aahkaa|

=== real cursor 4 : aahk|aa ===
public preedit: a hao| a
forward (virtual cursor -> preedit):
  |aahkaa  v=0  ->  |a hao a
  a|ahkaa  v=1  ->  |a hao a
  aa|hkaa  v=2  ->  a| hao a
  aah|kaa  v=3  ->  a h|ao a
  aahk|aa  v=4  ->  a hao| a
  aahka|a  v=5  ->  a hao| a
  aahkaa|  v=6  ->  a hao a|
reverse (preedit cursor -> input):
  |a hao a  ->  |aahkaa
  a| hao a  ->  aa|hkaa
  a |hao a  ->  aa|hkaa
  a h|ao a  ->  aah|kaa
  a ha|o a  ->  aah|kaa
  a hao| a  ->  aahk|aa
  a hao |a  ->  aahk|aa
  a hao a|  ->  aahkaa|

=== real cursor 5 : aahka|a ===
public preedit: a hao _|a
forward (virtual cursor -> preedit):
  |aahkaa  v=0  ->  |a hao _a
  a|ahkaa  v=1  ->  |a hao _a
  aa|hkaa  v=2  ->  a| hao _a
  aah|kaa  v=3  ->  a h|ao _a
  aahk|aa  v=4  ->  a hao| _a
  aahka|a  v=5  ->  a hao _|a
  aahkaa|  v=6  ->  a hao _a|
reverse (preedit cursor -> input):
  |a hao _a  ->  |aahkaa
  a| hao _a  ->  aa|hkaa
  a |hao _a  ->  aa|hkaa
  a h|ao _a  ->  aah|kaa
  a ha|o _a  ->  aah|kaa
  a hao| _a  ->  aahk|aa
  a hao |_a  ->  aahk|aa
  a hao _|a  ->  aahka|a
  a hao _a|  ->  aahkaa|

=== real cursor 6 : aahkaa| ===
public preedit: a hao a|
forward (virtual cursor -> preedit):
  |aahkaa  v=0  ->  |a hao a
  a|ahkaa  v=1  ->  |a hao a
  aa|hkaa  v=2  ->  a| hao a
  aah|kaa  v=3  ->  a h|ao a
  aahk|aa  v=4  ->  a hao| a
  aahka|a  v=5  ->  a hao| a
  aahkaa|  v=6  ->  a hao a|
reverse (preedit cursor -> input):
  |a hao a  ->  |aahkaa
  a| hao a  ->  aa|hkaa
  a |hao a  ->  aa|hkaa
  a h|ao a  ->  aah|kaa
  a ha|o a  ->  aah|kaa
  a hao| a  ->  aahk|aa
  a hao |a  ->  aahk|aa
  a hao a|  ->  aahkaa|
```
