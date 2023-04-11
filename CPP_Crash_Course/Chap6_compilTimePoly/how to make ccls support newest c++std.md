add .ccls file in the root path of my project works for me.
add these lines in .ccls file:
```
clang++
%h %cpp -std=c++20
```
I also add more flags in my file:
```
%h %cpp -std=c++20 -fconcepts
```
(https://github.com/MaskRay/ccls/wiki/Project-Setup#ccls-file)
(https://github.com/MaskRay/ccls/issues/802)
(https://codevion.github.io/index.html#!vim/coc.md)
