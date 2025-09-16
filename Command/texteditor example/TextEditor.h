#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <string>

// Receiver class - knows how to perform the actual operations
// This is the object that gets acted upon by commands
class TextEditor {
private:
    std::string content;    // The text content being edited
    int cursorPos;         // Current cursor position

public:
    TextEditor();
    
    // Core operations that commands will invoke
    void insertText(const std::string& text, int position);
    void deleteText(int position, int length);
    void replaceText(int position, int length, const std::string& newText);
    
    // Utility methods
    void setCursor(int position);
    int getCursor() const;
    std::string getContent() const;
    std::string getTextAt(int position, int length) const;
    int getLength() const;
    
    // Display the current state
    void display() const;
};

#endif