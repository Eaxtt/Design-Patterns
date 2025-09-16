#include "TextCommands.h"

// InsertCommand Implementation
InsertCommand::InsertCommand(TextEditor* ed, const std::string& txt, int pos) 
    : editor(ed), text(txt), position(pos) {}

void InsertCommand::execute() {
    // Delegate the actual work to the receiver (TextEditor)
    editor->insertText(text, position);
}

void InsertCommand::undo() {
    // Undo by deleting what we inserted
    editor->deleteText(position, text.length());
}

const char* InsertCommand::getDescription() const {
    return "Insert Text";
}

// DeleteCommand Implementation  
DeleteCommand::DeleteCommand(TextEditor* ed, int pos, int len) 
    : editor(ed), position(pos), length(len), deletedText("") {}

void DeleteCommand::execute() {
    // Store the text that will be deleted so we can restore it in undo
    deletedText = editor->getTextAt(position, length);
    
    // Delegate the actual work to the receiver (TextEditor)
    editor->deleteText(position, length);
}

void DeleteCommand::undo() {
    // Undo by reinserting the deleted text
    editor->insertText(deletedText, position);
}

const char* DeleteCommand::getDescription() const {
    return "Delete Text";
}

// ReplaceCommand Implementation
ReplaceCommand::ReplaceCommand(TextEditor* ed, int pos, int len, const std::string& newTxt) 
    : editor(ed), position(pos), length(len), newText(newTxt), oldText("") {}

void ReplaceCommand::execute() {
    // Store the original text so we can restore it in undo
    oldText = editor->getTextAt(position, length);
    
    // Delegate the actual work to the receiver (TextEditor)
    editor->replaceText(position, length, newText);
}

void ReplaceCommand::undo() {
    // Undo by restoring the original text
    editor->replaceText(position, newText.length(), oldText);
}

const char* ReplaceCommand::getDescription() const {
    return "Replace Text";
}