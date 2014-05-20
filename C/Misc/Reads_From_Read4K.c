Given a class which reads from a file in chunks of 4k, give a class which can satisfy requests for arbitrary amounts of data

// given:
class Read4K {
public:
  // @return number of bytes read
  int read4K(char* buf);
};
 
class ArbitraryIO {
public:
  // IMPLEMENT:
  // should return number of bytes read
  int read(int toRead, char* buf);
 
  ArbitraryIO(Read4K& read4K) : m_read4K(read4K) {}
private:
  Read4K& m_read4K;
};

toRead = 2
buf = 2
file = 

int Arbitrary::read(int toRead, char *buf) {
    int alreadyRead = 0, read;
    char tempBuf[4096];
    while (alreadyRead < toRead) {
        if (toRead - alReadyRead < 4096) {
            read = Read4K(tempBuf);
            if (read > toRead - alreadyRead) {
                memcpy(&buf[alreadyRead], tempBuf, toRead - alreadyRead);
                return toRead;
            } else {
                memcpy(&buf[alreadyRead], tempBuf, read);
                return alreadyRead + read;
            }
        }
        read = Read4K(&buf[alreadyRead]);
        alreadyRead = alreadyRead + read;
        if (read < 4096)
            break;
    }
    return alreadyRead;
}
