#ifndef _VERTEX_BUFFER_H_
#define _VERTEX_BUFFER_H_

namespace KonTiKi
{
    class IVertexDataBuffer
    {
    public:

        enum Usage
        {
            USAGE_STATIC_DRAW,
            USAGE_DYNAMIC_DRAW,
            USAGE_STREAM_DRAW,
        };

        enum Type {
            BF_ARRAY_BUFFER,
            BF_ELEMENT_ARRAY_BUFFER,
        };

        IVertexDataBuffer(Type type, unsigned size, const void* data, Usage usage): m_type(type)
            , m_size(size), m_usage(usage){}    
        virtual ~IVertexDataBuffer(void){}
/*
        virtual void Init(BindFlag bindFlag, unsigned size, const void* data, Usage usage)
        {
            m_bindFlag = bindFlag;
            m_usage = usage;
            m_size = size;
        }
*/

        unsigned GetSize(void) const
        {
            return m_size;
        }

        virtual void Update(unsigned offset, unsigned size, const void* data);  

        Type GetBindFlag(void) const
        {
            return m_type;
        }

        Usage GetUsage(void) const
        {
            return m_usage;
        }

    private:
        //BindFlag m_bindFlag;
        Type m_type;
        Usage m_usage;
        unsigned m_size;
    };
}
#endif
