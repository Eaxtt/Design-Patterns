#include <iostream>
#include "Expression.h"
#include "NumberExpression.h"
#include "AddExpression.h"
#include "SubtractExpression.h"
#include "Context.h"

using namespace std;

void example1_SimpleAddition() {
    cout << "\n========================================" << endl;
    cout << "EXAMPLE 1: Simple Addition" << endl;
    cout << "Expression: 5 + 3" << endl;
    cout << "========================================\n" << endl;
    
    // CLIENT manually builds the expression tree
    // Tree structure:
    //       Add
    //      /   \
    //     5     3
    
    Expression* expr = new AddExpression(
        new NumberExpression(5),
        new NumberExpression(3)
    );
    
    // Create context (not really used for this simple case, but required)
    Context context("5 + 3");
    
    // Evaluate
    cout << "\n--- Evaluating ---" << endl;
    int result = expr->interpret(context);
    
    cout << "\n=== RESULT: " << result << " ===" << endl;
    
    delete expr;
}

void example2_SimpleSubtraction() {
    cout << "\n\n========================================" << endl;
    cout << "EXAMPLE 2: Simple Subtraction" << endl;
    cout << "Expression: 10 - 4" << endl;
    cout << "========================================\n" << endl;
    
    // Tree:
    //       Sub
    //      /   \
    //    10     4
    
    Expression* expr = new SubtractExpression(
        new NumberExpression(10),
        new NumberExpression(4)
    );
    
    Context context("10 - 4");
    
    cout << "\n--- Evaluating ---" << endl;
    int result = expr->interpret(context);
    
    cout << "\n=== RESULT: " << result << " ===" << endl;
    
    delete expr;
}

void example3_NestedExpression() {
    cout << "\n\n========================================" << endl;
    cout << "EXAMPLE 3: Nested Expression" << endl;
    cout << "Expression: (5 + 3) - 2" << endl;
    cout << "========================================\n" << endl;
    
    // Tree structure:
    //          Sub
    //         /   \
    //       Add    2
    //      /   \
    //     5     3
    
    Expression* expr = new SubtractExpression(
        new AddExpression(
            new NumberExpression(5),
            new NumberExpression(3)
        ),
        new NumberExpression(2)
    );
    
    Context context("(5 + 3) - 2");
    
    cout << "\n--- Evaluating ---" << endl;
    int result = expr->interpret(context);
    
    cout << "\n=== RESULT: " << result << " ===" << endl;
    
    delete expr;
}

void example4_ComplexExpression() {
    cout << "\n\n========================================" << endl;
    cout << "EXAMPLE 4: Complex Expression" << endl;
    cout << "Expression: (10 - 3) + (5 - 2)" << endl;
    cout << "========================================\n" << endl;
    
    // Tree structure:
    //              Add
    //            /     \
    //          Sub      Sub
    //         /   \    /   \
    //       10    3   5     2
    
    Expression* expr = new AddExpression(
        new SubtractExpression(
            new NumberExpression(10),
            new NumberExpression(3)
        ),
        new SubtractExpression(
            new NumberExpression(5),
            new NumberExpression(2)
        )
    );
    
    Context context("(10 - 3) + (5 - 2)");
    
    cout << "\n--- Evaluating ---" << endl;
    int result = expr->interpret(context);
    
    cout << "\n=== RESULT: " << result << " ===" << endl;
    
    delete expr;
}

void explainPattern() {
    cout << "\n\n========================================" << endl;
    cout << "INTERPRETER PATTERN EXPLANATION" << endl;
    cout << "========================================\n" << endl;
    
    cout << "PARTICIPANTS:" << endl;
    cout << "-----------" << endl;
    
    cout << "\n1. ABSTRACTEXPRESSION: Expression" << endl;
    cout << "   - Base interface with interpret(Context&)" << endl;
    cout << "   - Common interface for all nodes" << endl;
    
    cout << "\n2. TERMINALEXPRESSION: NumberExpression" << endl;
    cout << "   - Leaf nodes in the tree" << endl;
    cout << "   - Represents actual numbers (5, 10, 42, etc.)" << endl;
    cout << "   - interpret() just returns the number" << endl;
    cout << "   - NO recursion - it's terminal!" << endl;
    
    cout << "\n3. NONTERMINALEXPRESSION: AddExpression, SubtractExpression" << endl;
    cout << "   - Composite nodes with children" << endl;
    cout << "   - Represents operations (+, -)" << endl;
    cout << "   - interpret() RECURSIVELY evaluates children" << endl;
    cout << "   - Then applies the operation to the results" << endl;
    
    cout << "\n4. CONTEXT: Context" << endl;
    cout << "   - Holds global information" << endl;
    cout << "   - In our simple version: tracks input string" << endl;
    cout << "   - Could store variables, functions, etc." << endl;
    
    cout << "\n5. CLIENT: main()" << endl;
    cout << "   - Builds the Abstract Syntax Tree (AST)" << endl;
    cout << "   - Calls interpret() to evaluate the expression" << endl;
    
    cout << "\n\nHOW IT WORKS:" << endl;
    cout << "-------------" << endl;
    cout << "1. Client builds a tree representing the expression" << endl;
    cout << "2. Each node knows how to interpret itself" << endl;
    cout << "3. Nonterminal nodes recursively interpret their children" << endl;
    cout << "4. Terminal nodes return their values" << endl;
    cout << "5. Results bubble up the tree to produce final answer" << endl;
    
    cout << "\n\nEXAMPLE TREE for '(5 + 3) - 2':" << endl;
    cout << "--------------------------------" << endl;
    cout << "        SubtractExpression        <-- Root evaluates to 6" << endl;
    cout << "           /         \\            " << endl;
    cout << "    AddExpression     NumberExpression(2)" << endl;
    cout << "       /    \\                     " << endl;
    cout << "  Number(5)  Number(3)             " << endl;
    cout << "                                   " << endl;
    cout << "Evaluation order (post-order traversal):" << endl;
    cout << "1. Number(5) -> 5" << endl;
    cout << "2. Number(3) -> 3" << endl;
    cout << "3. Add(5,3) -> 8" << endl;
    cout << "4. Number(2) -> 2" << endl;
    cout << "5. Subtract(8,2) -> 6" << endl;
    
    cout << "\n========================================\n" << endl;
}

int main() {
    cout << "INTERPRETER PATTERN - SIMPLE ARITHMETIC CALCULATOR" << endl;
    cout << "==================================================\n" << endl;
    
    example1_SimpleAddition();
    example2_SimpleSubtraction();
    example3_NestedExpression();
    example4_ComplexExpression();
    explainPattern();
    
    cout << "\n========================================" << endl;
    cout << "KEY TAKEAWAY" << endl;
    cout << "========================================" << endl;
    cout << "The Interpreter pattern builds a TREE where" << endl;
    cout << "each node knows how to evaluate itself!" << endl;
    cout << "\nTerminals (leaves) = actual values" << endl;
    cout << "Nonterminals (branches) = operations" << endl;
    cout << "\nEvaluation = recursive tree traversal!" << endl;
    cout << "========================================\n" << endl;
    
    return 0;
}