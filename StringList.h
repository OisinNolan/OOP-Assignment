#if ! defined ( STRINGLIST_H )
#define STRINGLIST_H

class StringList {
    private:
        struct StringNode {
            const char * str;
            StringNode * next;
        };
        StringNode * head;
    public:
        StringList();
        ~StringList();
        void add(const char * s);
        bool contains(const char * s);
};

#endif