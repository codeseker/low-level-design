#include <bits/stdc++.h>
using namespace std;

class Block {
    public:
    virtual void render() {}
};

class TextBlock : public Block {
    string text;
    public:
    TextBlock(string t) : text(t) {}
    void render() override {
        cout << "[Text: " << text << " ]" << endl;
    }
};

class ImageBlock : public Block {
    string url;
    public:
    ImageBlock(string u) : url(u) {}
    void render() override {
        cout << "[Image: " << url << " ]" << endl;
    }
};

class PdfBlock : public Block {
    string url;
    public:
    PdfBlock(string u) : url(u) {}
    void render() override {
        cout << "[PDF: " << url << " ]" << endl;
    }
};

class Document {
    vector<Block*> blocks;
    public:
    vector<Block*> getBlocks() {
        return blocks;
    }
    void addBlock(Block* b) {
        blocks.push_back(b);
    }
    void removeBlock(Block* b) {
        blocks.erase(remove(blocks.begin(), blocks.end(), b), blocks.end());
    }
};

class DocumentRenderer {
    Document* doc;
    public:
    DocumentRenderer(Document* d) : doc(d) {}

    void renderDocument() {
        for(Block* b: doc->getBlocks()) {
            b->render();
        }
    }
};



class User {
    string name, email;
    vector<Document> documents;
    public:
    User(string n, string e) : name(n), email(e) {}

    void getProfile() {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl; 
    }

    void addDocument(Document d) {
        documents.push_back(d);
    }
};

int main() {
    User john("John", "j@j.com");
    User sam("Sam", "s@s.com");

    Document doc1;
    doc1.addBlock(new TextBlock("Hello World!"));
    doc1.addBlock(new ImageBlock("image.png"));
    doc1.addBlock(new PdfBlock("pdf.pdf"));

    Document doc2;
    doc2.addBlock(new TextBlock("Sam's Document"));
    doc2.addBlock(new ImageBlock("image.png"));
    doc2.addBlock(new PdfBlock("pdf.pdf"));

    john.addDocument(doc1);
    sam.addDocument(doc2);

    DocumentRenderer renderer(&doc1);
    cout << "John's Document: " << endl;
    renderer.renderDocument();

    renderer = DocumentRenderer(&doc2);
    cout << "Sam's Document: " << endl;
    renderer.renderDocument();

    return 0;
}