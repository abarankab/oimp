#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Document {
private:
    const std::string Content;
public:
    Document(const std::string& s): Content(s) {}
    virtual void Save() const {
    }
};

class PlainTextDocument: public Document {
public:
    PlainTextDocument(const std::string& s): Document(s) {}
    void Save() override {
        std::cout << Content << "\n";
    }
};

class HTMLDocument: public Document {
public:
    HTMLDocument(const std::string& s): Document(s) {}
    void Save() override {
        std::cout << "<HTML><BODY>" << Content << "</BODY></HTML>\n";
    }
};

using DocumentCollection = std::vector<unique_ptr<Document>>;

void AddDocument(const std::string& content, const std::string& type, DocumentCollection& collection) {
    if (type == "plain")
        collection.push_back(unique_ptr<PlainTextDocument>(new PlainTextDocument(content)));
    else if (type == "html")
        collection.push_back(unique_ptr<HTMLDocument>(new HTMLDocument(content)));
}

void PrintCollection(const DocumentCollection& collection) {
    for (const auto& doc : collection)
        doc->Save();
}
