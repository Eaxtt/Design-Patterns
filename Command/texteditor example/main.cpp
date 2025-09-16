#include "TextEditor.h"
#include "TextCommands.h"
#include "EditorInvoker.h"
#include <iostream>

int main() {
    std::cout << "=== Command Pattern Text Editor Demo ===" << std::endl;
    
    // Create the receiver (the object that will be acted upon)
    TextEditor* editor = new TextEditor();
    
    // Create the invoker (manages command execution and history)
    EditorInvoker* invoker = new EditorInvoker();
    
    std::cout << "\nInitial state:" << std::endl;
    editor->display();
    
    // === Demonstrate the Command Pattern in Action ===
    
    // Client creates concrete commands and sets their receivers
    std::cout << "\n1. Inserting 'Hello World!' at position 0" << std::endl;
    Command* cmd1 = new InsertCommand(editor, "Hello World!", 0);
    invoker->executeCommand(cmd1);
    editor->display();
    
    std::cout << "\n2. Inserting ' How are you?' at position 12" << std::endl;
    Command* cmd2 = new InsertCommand(editor, " How are you?", 12);
    invoker->executeCommand(cmd2);
    editor->display();
    
    std::cout << "\n3. Replacing 'How are you' with 'Nice to meet you' at position 13" << std::endl;
    Command* cmd3 = new ReplaceCommand(editor, 13, 11, "Nice to meet you");
    invoker->executeCommand(cmd3);
    editor->display();
    
    std::cout << "\n4. Deleting 5 characters starting at position 5" << std::endl;
    Command* cmd4 = new DeleteCommand(editor, 5, 5);
    invoker->executeCommand(cmd4);
    editor->display();
    
    // Show command history
    invoker->showHistory();
    
    // === Demonstrate Undo/Redo functionality ===
    std::cout << "\n=== Testing Undo/Redo ===" << std::endl;
    
    std::cout << "\nUndoing last command..." << std::endl;
    invoker->undo();
    editor->display();
    
    std::cout << "\nUndoing another command..." << std::endl;
    invoker->undo();
    editor->display();
    
    std::cout << "\nRedoing a command..." << std::endl;
    invoker->redo();
    editor->display();
    
    std::cout << "\nAdding a new command after undo (this will clear redo history)" << std::endl;
    Command* cmd5 = new InsertCommand(editor, " INSERTED", 10);
    invoker->executeCommand(cmd5);
    editor->display();
    
    // Show final command history
    invoker->showHistory();
    
    std::cout << "\n=== Testing Undo All ===" << std::endl;
    while (invoker->canUndo()) {
        invoker->undo();
        editor->display();
    }
    
    std::cout << "\nTrying to undo when there's nothing to undo:" << std::endl;
    invoker->undo();
    
    std::cout << "\n=== Redo All ===" << std::endl;
    while (invoker->canRedo()) {
        invoker->redo();
        editor->display();
    }
    
    std::cout << "\nTrying to redo when there's nothing to redo:" << std::endl;
    invoker->redo();
    
    // === Demonstrate macro command (multiple commands as one) ===
    std::cout << "\n=== Demonstrating Sequential Commands ===" << std::endl;
    std::cout << "Executing multiple commands in sequence..." << std::endl;
    
    invoker->executeCommand(new DeleteCommand(editor, 0, editor->getLength())); // Clear all
    invoker->executeCommand(new InsertCommand(editor, "Command", 0));
    invoker->executeCommand(new InsertCommand(editor, " Pattern", 7));
    invoker->executeCommand(new InsertCommand(editor, " Demo", 15));
    
    editor->display();
    invoker->showHistory();
    
    // Clean up memory
    delete editor;
    delete invoker;
    
    std::cout << "\n=== Demo Complete ===" << std::endl;
    return 0;
}