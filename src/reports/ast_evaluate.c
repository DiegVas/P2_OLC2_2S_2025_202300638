#include "ast.h"
#include "../parser/semantic/semantic.h"

ASTVal *ast_evaluate(Expression *expr)
{
    ExpressionType type = get_expression_type(expr->type);
    switch (type)
    {
    case EXP_INTEGER:
        return create_ast_node(expr->value);
    case EXP_FLOAT:
        return create_ast_node(expr->value);
    case EXP_STRING:
        return create_ast_node(expr->value);
    case EXP_BOOLEAN:
        return create_ast_node(expr->value);
    case EXP_CHARACTER:
        return create_ast_node(expr->value);
    case EXP_DOUBLE:
        return create_ast_node(expr->value);
    case EXP_SUM:
    {
        ASTVal *node = create_ast_node("SUM");
        add_child(node, ast_evaluate(expr->right));
        add_child(node, create_ast_node("+"));
        add_child(node, ast_evaluate(expr->left));

        return node;
    }
    case EXP_SUBTRACT:
    {
        ASTVal *node = create_ast_node("SUBTRACT");
        add_child(node, ast_evaluate(expr->right));
        add_child(node, create_ast_node("-"));
        add_child(node, ast_evaluate(expr->left));

        return node;
    }
    case EXP_MULTIPLICATION:
    {
        ASTVal *node = create_ast_node("MULTIPLICATION");
        add_child(node, ast_evaluate(expr->right));
        add_child(node, create_ast_node("*"));
        add_child(node, ast_evaluate(expr->left));
        return node;
    }
    case EXP_DIVIDE:
    {
        ASTVal *node = create_ast_node("DIVIDE");
        add_child(node, ast_evaluate(expr->right));
        add_child(node, create_ast_node("/"));
        add_child(node, ast_evaluate(expr->left));
        return node;
    }
    case EXP_MODULO:
    {
        ASTVal *node = create_ast_node("MODULO");
        add_child(node, ast_evaluate(expr->right));
        add_child(node, create_ast_node("%"));
        add_child(node, ast_evaluate(expr->left));
        return node;
    }

    case EXP_NEGATIVE:
    {
        ASTVal *node = create_ast_node("NEGATIVE");
        add_child(node, create_ast_node("-"));
        add_child(node, ast_evaluate(expr->left));
        return node;
    }
    case EXP_CASTING:
    {
        ASTVal *node = create_ast_node("CASTING");
        add_child(node, create_ast_node(expr->value ? expr->value : "NULL"));
        add_child(node, ast_evaluate(expr->left));
        return node;
    }
    case EXP_BITWISE_AND:
    {
        ASTVal *node = create_ast_node("BITWISE_AND");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node("&"));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_BITWISE_OR:
    {
        ASTVal *node = create_ast_node("BITWISE_OR");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node("|"));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_BITWISE_XOR:
    {
        ASTVal *node = create_ast_node("BITWISE_XOR");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node("^"));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_BITWISE_LEFT_SHIFT:
    {
        ASTVal *node = create_ast_node("BITWISE_LEFT_SHIFT");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node("<<"));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_BITWISE_RIGHT_SHIFT:
    {
        ASTVal *node = create_ast_node("BITWISE_RIGHT_SHIFT");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node(">>"));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_EQUALS_OP:
    {
        ASTVal *node = create_ast_node("EQUALS_OP");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node(".equals"));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_EQUALS:
    {
        ASTVal *node = create_ast_node("EQUALS");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node("=="));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_NOT_EQUALS:
    {
        ASTVal *node = create_ast_node("NOT_EQUALS");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node("!="));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_LOGICAL_AND:
    {
        ASTVal *node = create_ast_node("LOGICAL_AND");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node("&&"));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_LOGICAL_OR:
    {
        ASTVal *node = create_ast_node("LOGICAL_OR");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node("||"));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_LOGICAL_NOT:
    {
        ASTVal *node = create_ast_node("LOGICAL_NOT");
        add_child(node, create_ast_node("!"));
        add_child(node, ast_evaluate(expr->left));
        return node;
    }
    case EXP_LESS:
    {
        ASTVal *node = create_ast_node("LESS");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node("<"));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_GREATER:
    {
        ASTVal *node = create_ast_node("GREATER");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node(">"));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_LESS_EQUALS:
    {
        ASTVal *node = create_ast_node("LESS_EQUALS");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node("<="));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_GREATER_EQUALS:
    {
        ASTVal *node = create_ast_node("GREATER_EQUALS");
        add_child(node, ast_evaluate(expr->left));
        add_child(node, create_ast_node(">="));
        add_child(node, ast_evaluate(expr->right));
        return node;
    }
    case EXP_PARSEINT:
    {
        ASTVal *node = create_ast_node("PARSEINT");
        add_child(node, ast_evaluate(expr->left));
        return node;
    }

    case EXP_PARSEDOUBLE:
    {
        ASTVal *node = create_ast_node("PARSEDOUBLE");
        add_child(node, ast_evaluate(expr->left));
        return node;
    }
    case EXP_PARSEFLOAT:
    {
        ASTVal *node = create_ast_node("PARSEFLOAT");
        add_child(node, ast_evaluate(expr->left));
        return node;
    }
    case EXP_VALUEOF:
    {
        ASTVal *node = create_ast_node("VALUEOF");
        add_child(node, ast_evaluate(expr->left));
        return node;
    }
    case EXP_JOIN:
    {
        ASTVal *node = create_ast_node("JOIN");
        ExpressionNode *current = expr->list ? expr->list->head : NULL;
        while (current)
        {
            add_child(node, ast_evaluate(current->expr));
            current = current->next;
        }
        return node;
    }
    case EXP_INDEXOF:
    {
        ASTVal *node = create_ast_node("INDEXOF");
        add_child(node, create_ast_node(expr->value ? expr->value : "NULL"));
        add_child(node, ast_evaluate(expr->left));
        return node;
    }
    case EXP_LENGTH:
    {
        ASTVal *node = create_ast_node("LENGTH");
        add_child(node, create_ast_node(expr->value ? expr->value : "NULL"));
        return node;
    }
    case EXP_ADD:
    {
        ASTVal *node = create_ast_node("ADD");
        add_child(node, create_ast_node(expr->value ? expr->value : "NULL"));
        add_child(node, ast_evaluate(expr->left));
        return node;
    }
    case EXP_ID:
        return create_ast_node(expr->value);
    case EXP_FUNCTION_CALL:
    {
        ASTVal *node = create_ast_node("FUNCTION_CALL");
        add_child(node, create_ast_node(expr->value ? expr->value : "NULL"));
        ExpressionNode *current = expr->list ? expr->list->head : NULL;
        ASTVal *params_node = create_ast_node("PARAMETERS");
        while (current)
        {
            add_child(params_node, ast_evaluate(current->expr));
            current = current->next;
        }
        add_child(node, params_node);
        return node;
    }
    default:
        return create_ast_node("UNKNOWN");
    }
}