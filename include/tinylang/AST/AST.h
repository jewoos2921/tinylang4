//
// Created by jewoo on 2021-06-28.
//

#pragma once

#include "tinylang/Basic/LLVM.h"
#include "tinylang/Basic/TokenKinds.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/APSInt.h"
#include "llvm/Support/SMLoc.h"
#include <vector>
#include <string>


namespace tinylang {
    class Decl;

    class FormalParameterDeclaration;

    class Expr;

    class Stmt;

    using DeclList = std::vector<Decl *>;
    using FormalParamList = std::vector<FormalParameterDeclaration *>;
    using ExprList = std::vector<Expr *>;
    using StmtList = std::vector<Stmt *>;

    class Ident {
        SMLoc Loc;
        StringRef Name;
    public:
        Ident(SMLoc Loc, const StringRef &Name)
                : Loc(Loc), Name(Name) {}

        SMLoc getLocation() { return Loc; }

        const StringRef &getName() { return Name; }

    };

    using IdentList = std::vector<std::pair<SMLoc, StringRef>>;

    class Decl {
    public:
        enum DeclKind {
            DK_MODULE,
            DK_CONST,
            DK_TYPE,
            DK_VAR,
            DK_PARAM,
            DK_PROC
        };
    private:
        const DeclKind Kind;
    protected:
        Decl *EnclosingDecl;
        SMLoc Loc;
        StringRef Name;
    public:
        Decl(DeclKind Kind, Decl *EnclosingDecl,
             SMLoc Loc, StringRef Name) :
                Kind(Kind),
                EnclosingDecl(EnclosingDecl), Loc(Loc),
                Name(Name) {}

        DeclKind getKind() const { return Kind; }

        SMLoc getLocation() { return Loc; }

        StringRef getName() { return Name; }

        Decl *getEnclosingDecl() { return EnclosingDecl; }

    };

    class ModuleDeclaration : public Decl {
        DeclList Decls;
        StmtList Stmts;
    public:
        ModuleDeclaration(Decl *EnclosingDecl,
                          SMLoc Loc, StringRef Name) :
                Decl(DK_MODULE, EnclosingDecl, Loc, Name) {}

        ModuleDeclaration(Decl *EnclosingDecl,
                          SMLoc Loc, StringRef Name, DeclList &Decls,
                          StmtList &Stmts) :
                Decl(DK_MODULE, EnclosingDecl, Loc, Name),
                Decls(Decls), Stmts(Stmts) {}

        const DeclList &getDecls() { return Decls; }

        const StmtList &getStmts() { return Stmts; }

        void setDecls(DeclList &D) { Decls = D; }

        void setStmts(StmtList &S) { Stmts = S; }

        static bool classof(const Decl *D) {
            return D->getKind() == DK_MODULE;
        }
    };

    class ConstantDeclaration : public Decl {
        Expr *E;
    public:
        ConstantDeclaration(Decl *EnclosingDecl, SMLoc Loc,
                            StringRef Name, Expr *E) :
                Decl(DK_CONST, EnclosingDecl, Loc, Name), E(E) {}

        Expr *getExpr() { return E; }

        static bool classof(const Decl *D) {
            return D->getKind() == DK_CONST;
        }
    };

    class TypeDeclaration : public Decl {
    public:
        TypeDeclaration(Decl *EnclosingDecl, SMLoc Loc,
                        StringRef Name) :
                Decl(DK_TYPE, EnclosingDecl, Loc, Name) {}

        static bool classof(const Decl *D) {
            return D->getKind() == DK_TYPE;
        }
    };

    class VariableDeclaration : public Decl {
        TypeDeclaration *Ty;
    public:
        VariableDeclaration(Decl *EnclosingDecl, SMLoc Loc,
                            StringRef Name, TypeDeclaration *Ty) :
                Decl(DK_VAR, EnclosingDecl, Loc, Name), Ty(Ty) {}

        TypeDeclaration *getType() { return Ty; }

        static bool classof(const Decl *D) {
            return D->getKind() == DK_VAR;
        }
    };

    class FormalParameterDeclaration : public Decl {
        TypeDeclaration *Ty;
        bool IsVar;
    public:
        FormalParameterDeclaration(Decl *EnclosingDecl, SMLoc Loc,
                                   StringRef Name, TypeDeclaration *Ty, bool IsVar) :
                Decl(DK_PARAM, EnclosingDecl, Loc, Name), Ty(Ty), IsVar(IsVar) {}

        TypeDeclaration *getType() { return Ty; }

        bool isVar() { return IsVar; }

        static bool classof(const Decl *D) {
            return D->getKind() == DK_PARAM;
        }
    };

    class ProcedureDeclaration : public Decl {
        FormalParamList Params;
        TypeDeclaration *RetType;
        DeclList Decls;
        StmtList Stmts;

    public:
        ProcedureDeclaration(Decl *EnclosingDecl, SMLoc Loc,
                             StringRef Name) :
                Decl(DK_PROC, EnclosingDecl, Loc, Name) {}

        ProcedureDeclaration(Decl *EnclosingDecl, SMLoc Loc,
                             StringRef Name,
                             FormalParamList &Params,
                             TypeDeclaration *RetType,
                             DeclList &Decls,
                             StmtList &Stmts) :
                Decl(DK_PROC, EnclosingDecl, Loc, Name), Params(Params), RetType(RetType),
                Decls(Decls),
                Stmts(Stmts) {}

        const FormalParamList &getFormalParams() { return Params; }

        void setFormalParams(FormalParamList &FP) { Params = FP; }

        TypeDeclaration *getRetType() { return RetType; }

        void setRetType(TypeDeclaration *Ty) { RetType = Ty; }

        const DeclList &getDecls() { return Decls; }

        void setDecls(DeclList &D) { Decls = D; }

        const StmtList &getStmts() { return Stmts; }

        void setStmts(StmtList &S) { Stmts = S; }

        static bool classof(const Decl *D) {
            return D->getKind() == DK_PROC;
        }
    };

    class OperatorInfo {
        SMLoc Loc;
        uint32_t Kind: 16;
        uint32_t IsUnspecified: 1;
    public:
        OperatorInfo() : Loc(), Kind(tok::unknown), IsUnspecified(true) {}

        OperatorInfo(SMLoc Loc, tok::TokenKind Kind, bool isUnspecified = false) :
                Loc(Loc), Kind(Kind), IsUnspecified(IsUnspecified) {}

        SMLoc getLocation() const { return Loc; }

        tok::TokenKind getKind() const {
            return static_cast<tok::TokenKind>(Kind);
        }

        bool isUnspecified() const { return IsUnspecified; }

    };

    class Expr {
    public:
        enum ExprKind {
            EK_INFIX,
            EK_PREFIX,
            EK_INT,
            EK_BOOL,
            EK_VAR,
            EK_CONST,
            EK_FUNC
        };
    private:
        const ExprKind Kind;
        TypeDeclaration *Ty;
        bool IsConstant;
    protected:
        Expr(ExprKind Kind, TypeDeclaration *Ty, bool IsConst) :
                Kind(Kind), Ty(Ty), IsConstant(IsConst) {}

    public:
        TypeDeclaration *getType() { return Ty; }

        ExprKind getKind() const { return Kind; }

        void setType(TypeDeclaration *T) { Ty = T; }

        bool isConst() { return IsConstant; }
    };

    class InfixExpression : public Expr {
        Expr *Left;
        Expr *Right;
        const OperatorInfo Op;

    public:
        InfixExpression(Expr *left, Expr *right,
                        OperatorInfo op,
                        TypeDeclaration *ty, bool isConst) :
                Expr(EK_INFIX, ty, isConst), Left(left), Right(right), Op(op) {}

        Expr *getLeft() { return Left; }

        Expr *getRight() { return Right; }

        const OperatorInfo &getOperatorInfo() { return Op; }

        static bool classof(const Expr *E) {
            return E->getKind() == EK_INFIX;
        }
    };

    class PrefixExpression : public Expr {
        Expr *E;
        const OperatorInfo Op;
    public:
        PrefixExpression(Expr *E,
                         OperatorInfo Op,
                         TypeDeclaration *Ty, bool IsConst) :
                Expr(EK_PREFIX, Ty, IsConst), E(E), Op(Op) {}

        Expr *getExpr() { return E; }

        const OperatorInfo &getOperatorInfo() { return Op; }

        static bool classof(const Expr *E) {
            return E->getKind() == EK_PREFIX;
        }
    };

    class IntegerLiteral : public Expr {
        SMLoc Loc;
        llvm::APSInt Value;
    public:
        IntegerLiteral(SMLoc Loc, const llvm::APSInt &Value,
                       TypeDeclaration *Ty) :
                Expr(EK_INT, Ty, true), Loc(Loc), Value(Value) {}

        llvm::APSInt &getValue() { return Value; }

        static bool classof(const Expr *E) {
            return E->getKind() == EK_INT;
        }
    };

    class BooleanLiteral : public Expr {
        bool Value;
    public:
        BooleanLiteral(bool Value,
                       TypeDeclaration *Ty) :
                Expr(EK_BOOL, Ty, true), Value(Value) {}

        bool getValue() { return Value; }

        static bool classof(const Expr *E) {
            return E->getKind() == EK_BOOL;
        }
    };

    class VariableAccess : public Expr {
        Decl *Var;
    public:
        VariableAccess(VariableDeclaration *Var) :
                Expr(EK_VAR, Var->getType(), false), Var(Var) {}

        VariableAccess(FormalParameterDeclaration *Param) :
                Expr(EK_VAR, Param->getType(), false), Var(Param) {}

        Decl *getDecl() { return Var; }

        static bool classof(const Expr *E) {
            return E->getKind() == EK_VAR;
        }
    };

    class ConstantAccess : public Expr {
        ConstantDeclaration *Const;
    public:
        ConstantAccess(ConstantDeclaration *Const) :
                Expr(EK_CONST, Const->getExpr()->getType(), true), Const(Const) {}

        ConstantDeclaration *getDecl() { return Const; }

        static bool classof(const Expr *E) {
            return E->getKind() == EK_CONST;
        }
    };

    class FunctionCallExpr : public Expr {
        ProcedureDeclaration *Proc;
        ExprList Params;
    public:
        FunctionCallExpr(ProcedureDeclaration *Proc,
                         ExprList Params) :
                Expr(EK_FUNC, Proc->getRetType(), false), Proc(Proc), Params(Params) {}

        const ExprList &getParams() { return Params; }

        ProcedureDeclaration *getDecl() { return Proc; }

        static bool classof(const Expr *E) {
            return E->getKind() == EK_FUNC;
        }
    };

    class Stmt {
    public:

        enum StmtKind {
            SK_ASSIGN,
            SK_PROC_CALL,
            SK_IF,
            SK_WHITE,
            SK_RETURN
        };
    private:
        const StmtKind Kind;
    protected:
        Stmt(StmtKind Kind) : Kind(Kind) {}

    public:
        StmtKind getKind() const { return Kind; }

    };

    class AssignmentStatement : public Stmt {
        VariableDeclaration *Var;
        Expr *E;
    public:
        AssignmentStatement(VariableDeclaration *Var, Expr *E) :
                Stmt(SK_ASSIGN), Var(Var), E(E) {}

        VariableDeclaration *getVar() { return Var; }

        Expr *getExpr() { return E; }

        static bool classof(const Stmt *S) {
            return S->getKind() == SK_ASSIGN;
        }
    };

    class ProcedureCallStatement : public Stmt {
        ProcedureDeclaration *Proc;
        ExprList Params;
    public:
        ProcedureCallStatement(ProcedureDeclaration *Proc, ExprList &Params) :
                Stmt(SK_PROC_CALL), Proc(Proc), Params(Params) {}

        ProcedureDeclaration *getProc() { return Proc; }

        const ExprList &getParams() { return Params; }

        static bool classof(const Stmt *S) {
            return S->getKind() == SK_PROC_CALL;
        }
    };

    class IfStatement : public Stmt {
        Expr *Cond;
        StmtList IfStmts;
        StmtList ElseStmts;
    public:
        IfStatement(Expr *Cond, StmtList &IfStmts, StmtList &ElseStmts) : Stmt(SK_IF), Cond(Cond), IfStmts(IfStmts),
                                                                          ElseStmts(ElseStmts) {}

        Expr *getCond() { return Cond; }

        const StmtList &getIfStmts() { return IfStmts; }

        const StmtList &getElseStmts() { return ElseStmts; }

        static bool classof(const Stmt *S) {
            return S->getKind() == SK_IF;
        }
    };

    class WhileStatement : public Stmt {
        Expr *Cond;
        StmtList Stmts;
    public:
        WhileStatement(Expr *Cond, StmtList &stmts) : Stmt(SK_WHITE), Cond(Cond), Stmts(stmts) {}

        Expr *getCond() { return Cond; }

        const StmtList &getWhileStmts() { return Stmts; }

        static bool classof(const Stmt *S) {
            return S->getKind() == SK_WHITE;
        }
    };

    class ReturnStatement : public Stmt {
        Expr *RetVal;
    public:
        ReturnStatement(Expr *RetVal) : Stmt(SK_RETURN), RetVal(RetVal) {}

        Expr *getRetVal() { return RetVal; }

        static bool classof(const Stmt *S) {
            return S->getKind() == SK_RETURN;
        }
    };
}

