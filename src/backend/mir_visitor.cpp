//
// Created by Yunming Zhang on 2/10/17.
//

//
// Created by Yunming Zhang on 1/24/17.
//


#include <graphit/backend/mir_visitor.h>
#include <graphit/backend/mir.h>

namespace graphit {
    namespace mir {

        void MIRVisitor::visit(Program::Ptr program) {
            for (auto elem : program->elems) {
                elem->accept(this);
            }
        }

        void MIRVisitor::visit(Stmt::Ptr stmt) {
            stmt->expr->accept(this);
        };

        void MIRVisitor::visit(Expr::Ptr expr) {
            expr->accept(this);
        };


        void MIRVisitor::visit(AddExpr::Ptr expr) {
            visitBinaryExpr(expr);
        }

        void MIRVisitor::visit(MinusExpr::Ptr expr) {
            visitBinaryExpr(expr);
        }

        void MIRVisitor::visitBinaryExpr(BinaryExpr::Ptr expr) {
            expr->lhs->accept(this);
            expr->rhs->accept(this);
        }
    }
}