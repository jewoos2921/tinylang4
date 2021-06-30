//
// Created by jewoo on 2021-06-28.
//

#ifndef TINYLANG3_SCOPE_H
#define TINYLANG3_SCOPE_H

#include "tinylang/Basic/LLVM.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/StringMap.h"

namespace tinylang {
    class Decl;

    class Scope {
        Scope *Parent;
        StringMap<Decl *> Symbols;
    public:
        Scope(Scope *Parent = nullptr) : Parent(Parent) {}

        bool insert(Decl *Declaration);

        Decl *lookup(StringRef Name);

        Scope *getParent() { return Parent; }
    };

}
#endif //TINYLANG3_SCOPE_H
