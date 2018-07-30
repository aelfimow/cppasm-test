/*! \file streamdest_buf.h
    \brief Class for Assembly Stream destination buffer.
*/
#ifdef STREAM_DEST_BUF_H
#error Already included
#else
#define STREAM_DEST_BUF_H

/*! \class Assembly stream destination buffer */
class streamdest_buf: public streamdest
{
    public:
        streamdest_buf();
        ~streamdest_buf();

        void clear();
        std::string get() const;

        void space() override;
        void indent() override;
        void write(const std::string &str) override;
        void writeln(const std::string &str) override;

    private:
        std::string m_buf;

    public:
        streamdest_buf(const streamdest_buf &instance) = delete;
        streamdest_buf(const streamdest_buf &&instance) = delete;
        streamdest_buf &operator=(const streamdest_buf &instance) = delete;
        streamdest_buf &operator=(const streamdest_buf &&instance) = delete;
};

#endif
