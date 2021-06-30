//
// Created by jewoo on 2021-06-28.
//

#ifndef TINYLANG3_TOKEN_H
#define TINYLANG3_TOKEN_H

#include "tinylang/Basic/LLVM.h"
#include "tinylang/Basic/TokenKinds.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/SMLoc.h"

namespace tinylang {
    class Lexer;

    class Token {
        friend class Lexer;

        const char *Ptr;
        size_t Length;
        tok::TokenKind Kind;
    public:
        tok::TokenKind getKind() const { return Kind; }

        void setKind(tok::TokenKind K) { Kind = K; }

        bool is(tok::TokenKind K) const { return Kind == K; }

        bool isNot(tok::TokenKind K) const { return Kind != K; }

        bool isOneOf(tok::TokenKind K1, tok::TokenKind K2) const {
            return is(K1) || is(K2);
        }

        template<typename... Ts>
        bool isOneOf(tok::TokenKind K1, tok::TokenKind K2, Ts... Ks) const {
            return is(K1) || isOneOf(K2, Ks...);
        }

        const char *getName() const {
            return tok::getTokenName(Kind);
        }

        SMLoc getLocation() const {
            return SMLoc::getFromPointer(Ptr);
        }

        size_t getLength() const { return Length; }

        StringRef getIdentifier() {
            assert(is(tok::identifier) && "Cannot get identifier of non-identifier");
            return StringRef(Ptr, Length);
        }

        StringRef getLiteralData() {
            assert(isOneOf(tok::integer_literal,
                           tok::string_literal) &&
                   "Cannot get literal data of non-literal");
            return StringRef(Ptr, Length);
        }
    };
}
#endif //TINYLANG3_TOKEN_H
