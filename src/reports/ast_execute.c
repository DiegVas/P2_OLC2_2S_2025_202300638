#include "ast.h"
#include "../parser/semantic/semantic.h"

ASTVal *ast_execute(Instruccion *instr)
{
    ExecuteType instruction_t = get_instruction_type(instr->InstType);

    switch (instruction_t)
    {
    case DECLARATION:
    {
        ASTVal *node = create_ast_node("DECLARATION");

        if (strcmp(instr->symbolType, "FUNCTION") == 0)
        {
            return create_ast_node("FUNCTION_DECLARATION");
        }

        if (strcmp(instr->symbolType, "VOID") == 0)
        {
            return create_ast_node("VOID_FUNCTION_DECLARATION");
        }

        if (strcmp(instr->symbolType, "LIST") == 0)
        {
            return create_ast_node("LIST_DECLARATION");
        }

        if (strcmp(instr->symbolType, "MATRIX") == 0)
        {
            return create_ast_node("MATRIX_DECLARATION");
        }

        if (strcmp(instr->symbolType, "VECTOR") == 0)
        {
            return create_ast_node("VECTOR_DECLARATION");
        }

        add_child(node, ast_evaluate(instr->value));
        add_child(node, create_ast_node("="));
        add_child(node, create_ast_node(instr->id ? instr->id : "NULL"));
        add_child(node, create_ast_node(instr->type ? instr->type : "NULL"));
        return node;
    }

    case ASSIGNMENT:

    {
        ASTVal *node = create_ast_node("ASSIGNMENT");
        add_child(node, ast_evaluate(instr->value));
        add_child(node, create_ast_node("="));
        add_child(node, create_ast_node(instr->id ? instr->id : "NULL"));

        return node;
    }

    case EXP_PRINTLN:
    {

        ASTVal *node = create_ast_node("PRINTLN");
        add_child(node, ast_evaluate(instr->value));
        return node;
    }
    case IF_STATEMENT:
    {
        ASTVal *node = create_ast_node("IF");
        add_child(node, ast_evaluate(instr->ifData->condition));

        if (instr->ifData->elseIfs)
        {
            IfNode *curr = instr->ifData->elseIfs->head;
            while (curr)
            {
                add_child(node, create_ast_node("ELSEIF"));
                add_child(node, ast_evaluate(curr->IfData->condition));
                if (curr->IfData->block)
                {
                    InstruccionNode *curr_instr = curr->IfData->block->head;
                    while (curr_instr)
                    {
                        add_child(node, ast_execute(curr_instr->instr));
                        curr_instr = curr_instr->next;
                    }
                }
                curr = curr->next;
            }
        }

        if (instr->ifData->block)
        {
            InstruccionNode *curr = instr->ifData->block->head;
            while (curr)
            {
                add_child(node, ast_execute(curr->instr));
                curr = curr->next;
            }
        }

        if (instr->ifData->elseBlock)
        {
            add_child(node, create_ast_node("ELSE"));
            InstruccionNode *curr = instr->ifData->elseBlock->head;
            while (curr)
            {
                add_child(node, ast_execute(curr->instr));
                curr = curr->next;
            }
        }
        return node;
    }
    case SWITCH_STATEMENT:
    {
        return create_ast_node("SWITCH");
    }
    case WHILE_STATEMENT:
    {
        return create_ast_node("WHILE");
    }
    case FOREACH_STATEMENT:
    {
        return create_ast_node("FOREACH");
    }
    case FOR_STATEMENT:
    {
        return create_ast_node("FOR");
    }
    case BREAK_STATEMENT:
    {
        ASTVal *node = create_ast_node("BREAK");
        return node;
    }
    case CONTINUE_STATEMENT:
    {
        ASTVal *node = create_ast_node("CONTINUE");
        return node;
    }
    case RETURN_STATEMENT:
    {

        ASTVal *node = create_ast_node("RETURN");
        if (instr->value)
            add_child(node, ast_evaluate(instr->value));
        return node;
    }
    case VOID_CALL:
    {
        ASTVal *node = create_ast_node("VOID_CALL");
        add_child(node, create_ast_node(instr->id ? instr->id : "NULL"));

              return node;
    }
    case BLOCK_STATEMENT:
    {
        ASTVal *node = create_ast_node("BLOCK");
        InstruccionNode *curr = instr->body ? instr->body->head : NULL;
        while (curr)
        {
            add_child(node, ast_execute(curr->instr));
            curr = curr->next;
        }
        return node;
    }

    default:
        break;
    }

    return create_ast_node(instr->InstType);
}