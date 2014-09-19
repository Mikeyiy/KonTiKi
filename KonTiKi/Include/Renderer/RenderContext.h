#ifndef _RENDER_CONTEXT_H_
#define _RENDER_CONTEXT_H_

namespace KonTiKi
{
    struct RenderContext
    {
        enum Cull 
        {
            CULL_BACK,    
            CULL_FRONT,
            CULL_OFF
        }; 
        Cull cull;

        bool zWrite;        

        enum ZTest
        {
            ZTEST_LESS,
            ZTES_TGREATER,
            ZTES_LEQUAL,
            ZTES_GEQUAL,
            ZTES_EQUAL,
            ZTES_NOTEQUAL,
            ZTES_ALWAYS
        };
        ZTest ztest;

        float factor;
        float units;

        enum AlphaTest
        {
            ALPHATEST_GREATER, 
            ALPHATEST_GEQUAL,
            ALPHATEST_LESS,
            ALPHATEST_LEQUAL,
            ALPHATEST_NOTEQUAL,
            ALPHATEST_ALWAYS,
            ALPHATEST_NEVER,
        };

        enum Blend 
        {
            BLEND_ONE,
            BLEND_ZERO,
            BLEND_SRC_COLOR,
            BLEND_SRC_ALPHA,
            BLEND_DST_COLOR,
            BLEND_DST_ALPHA,
            BLEND_ONE_MINUS_SRC_COLOR,
            BLEND_ONE_MINUS_SRC_ALPHA,
            BLEND_ONE_MINUS_DST_COLOR,
            BLEND_ONE_MINUS_DST_ALPHA,
        };

        enum BlendOp
        {
            BLENDOP_MIN,
            BLENDOP_MAX,
            BLENDOP_SUB,
            BLENDOP_REV_SUB,
        };
    };

   
}

#endif

