#ifndef TEXTCOMMANDS_H
#define TEXTCOMMANDS_H

#include "Command.h"
#include "TextEditor.h"
#include <string>

// ConcreteCommand for inserting text
// Binds a Receiver (TextEditor) with an action (insert)
class InsertCommand : public Command {
private:
    TextEditor* editor;     // Reference to receiver
    std::string text;       // Text to insert
    int position;          // Where to insert
    
public:
    InsertCommand(TextEditor* ed, const std::string& txt, int pos);
    
    void execute() override;        // Execute the insert operation
    void undo() override;          // Undo by deleting what was inserted
    const char* getDescription() const override;
};

// ConcreteCommand for deleting text
class DeleteCommand : public Command {
private:
    TextEditor* editor;     // Reference to receiver
    int position;          // Where to start deleting
    int length;            // How many characters to delete
    std::string deletedText; // Store deleted text for undo
    
public:
    DeleteCommand(TextEditor* ed, int pos, int len);
    
    void execute() override;        // Execute the delete operation
    void undo() override;          // Undo by reinserting deleted text
    const char* getDescription() const override;
};

// ConcreteCommand for replacing text
class ReplaceCommand : public Command {
private:
    TextEditor* editor;     // Reference to receiver
    int position;          // Where to start replacing
    int length;            // How many characters to replace
    std::string newText;   // New text to insert
    std::string oldText;   // Original text (for undo)
    
public:
    ReplaceCommand(TextEditor* ed, int pos, int len, const std::string& newTxt);
    
    void execute() override;        // Execute the replace operation
    void undo() override;          // Undo by restoring original text
    const char* getDescription() const override;
};

#endif