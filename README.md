Schreier Sims
=============

The [Schreier Sims][schreier-sims] algorithm is used to answer
numerous questions about finite groups. This includes

* finding the order of the group.
* determine if a permutation is a member of the group.

This repository provides a [C++][c++] implementation.

Setup
-----

### googletest

We are relying on [googletest][] to provide a unit testing
framework. This repository uses version [1.7.0][gtest-1.7.0].

### Makefile

A `Makefile` is present to automate the task of compiling and
linking. Tweak the `Makefile` to point it to the location of the
[googletest][] files.

[schreier-sims]: http://en.wikipedia.org/wiki/Schreier%E2%80%93Sims_algorithm
[c++]: http://en.wikipedia.org/wiki/C++
[googletest]: https://code.google.com/p/googletest/
[gtest-1.7.0]: https://code.google.com/p/googletest/downloads/detail?name=gtest-1.7.0.zip
