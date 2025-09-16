#include "TextEditor.h"

// Constructor - initialize with empty content and cursor at beginning
TextEditor::TextEditor() : content(""), cursorPos(0) {}

// Insert text at specified position
void TextEditor::insertText(const std::string& text, int position) {
    if (position < 0) position = 0;
    if (position > (int)content.length()) position = content.length();
    
    content.insert(position, text);
    cursorPos = position + text.length(); // Move cursor after inserted text
}

// Delete text starting at position for given length
void TextEditor::deleteText(int position, int length) {
    if (position < 0 || position >= (int)content.length() || length <= 0) {
        return; // Invalid parameters
    }
    
    // Ensure we don't delete beyond the string
    if (position + length > (int)content.length()) {
        length = content.length() - position;
    }
    
    content.erase(position, length);
    cursorPos = position; // Move cursor to deletion point
}

// Replace text at position with new text
void TextEditor::replaceText(int position, int length, const std::string& newText) {
    if (position < 0 || position >= (int)content.length() || length <= 0) {
        return; // Invalid parameters
    }
    
    // Ensure we don't replace beyond the string
    if (position + length > (int)content.length()) {
        length = content.length() - position;
    }
    
    content.replace(position, length, newText);
    cursorPos = position + newText.length(); // Move cursor after replacement
}

// Set cursor position
void TextEditor::setCursor(int position) {
    if (position < 0) position = 0;
    if (position > (int)content.length()) position = content.length();
    cursorPos = position;
}

// Get current cursor position
int TextEditor::getCursor() const {
    return cursorPos;
}

// Get the entire content
std::string TextEditor::getContent() const {
    return content;
}

// Get text at specific position with given length
std::string TextEditor::getTextAt(int position, int length) const {
    if (position < 0 || position >= (int)content.length() || length <= 0) {
        return "";
    }
    
    if (position + length > (int)content.length()) {
        length = content.length() - position;
    }
    
    return content.substr(position, length);
}

// Get total length of content
int TextEditor::getLength() const {
    return content.length();
}

// Display current state with cursor position indicated
void TextEditor::display() const {
    std::cout << "Content: \"" << content << "\"" << std::endl;
    std::cout << "Cursor at position: " << cursorPos << std::endl;
    
    // Show cursor position visually
    std::cout << "         ";
    for (int i = 0; i < cursorPos; ++i) {
        std::cout << " ";
    }
    std::cout << "^" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}