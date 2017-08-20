# compilers
Some notes I compiled about compilers.

# about compilers
* definitions:
    * software that transforms source code of a language into another (target)
      language. typically, this involves translating from a higher-level
      language to a lower level one (assembly, object code, etc.)
* types of compilers:
    * cross compiler
    * bootstrap compiler - [wikiArticle](https://en.wikipedia.org/wiki/Bootstrapping_(compilers))
        * bootstrapping is the process of writing a compiler (or assembler) in
          the source programming language that it intends to compile
    * decompiler - the opposite of a compiler
    * just-in-time compiler (JIT)
* concepts:
    * parsing
    * control flow graphs - "reducible" vs "non-reducible"
    * dominator trees
    * static single assignment (SSA) form
    * common subexpression elimination & copy propagation
        * aliasing - "kill instructions"
    * register allocations
    * instruction scheduling
    * speculative processor features
        * control & data speculation
    * caching & cache-related optimizations
* compiling C/C++ (in a nutshell)
    * preprocessing
        * handle the preprocesser directorives (#include, #define, etc.)
    * compilation
        * parse source code and produce assembly
        * then an assembler converts to machine code in an object file that
          contains references (some defined some not) to symbols by their name.
    * linking
        * final stage of compilation where all the symbols are resolved by
          reading them from a library or other object file
        * can be done dynamically (right at run-time start) by the dynamic
          linker 
        * or resolved when compiled, which is referred to as statically linking

## cross compilers
* a compiler capable of compiling for a platform other than which the compiler
  is running on [wikiArticle](https://en.wikipedia.org/wiki/Cross_compiler)
* methods for cross compilation:
    * using a cross compiler (and toolchain) executables directly
        * pros: minimal setup, quicker(?)
    * create an environment (sb2) to emulate the CPU of the target platform
        * this is useful for several reasons (1) you are able to run your
          programs (maybe even unit tests!) (2) if you are using tools like
          ./configure when cross compiling, this will help simulate the target
          system

