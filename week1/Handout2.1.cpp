a) Vector<eMailMsg> mailVector;


b)
void RemoveSpam(Vector<eMailMsg> & v) {
    for (int i = v.size() - 1; i >= 0; i--) {
        eMailMsg mail = v[i];
        if (mail.subject.find("SPAM") == 0) {
            v.removeAt(i);
        }
    }
}

c)
struct eMailMsg {
    Vector<string> to;
    string from;
    string message;
    string subject;
    int date;
    int time; };
