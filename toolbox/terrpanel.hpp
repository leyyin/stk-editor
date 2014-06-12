#ifndef TERRPANEL_HPP
#define TERRPANEL_HPP

#include <irrlicht.h>

#include "entities/terrain.hpp"

using namespace irr;
using namespace gui;
using namespace core;

class TerrPanel
{
public:
    // first gui element id
    static const int FGEI = 200;
    
    enum
    {
        H_EDGE_1 = FGEI,
        H_EDGE_2,
        H_EDGE_3,
        H_RADIUS,
        H_INTENSITY,
        H_MIN_CHECK_BOX,
        H_MAX_CHECK_BOX,
        H_MIN_EDIT_BOX,
        H_MAX_EDIT_BOX
    };

private:

    // private variables:

    static TerrPanel*       m_terr_panel;

    IGUIWindow*             m_wndw;

    IGUIScrollBar*          m_h_radius;
    IGUIScrollBar*          m_h_intensity;

    IGUIImage*              m_active_edge_frame;

    IGUIEditBox*            m_h_min_value;
    IGUIEditBox*            m_h_max_value;

    IGUICheckBox*           m_h_min_cb;
    IGUICheckBox*           m_h_max_cb;
    
    Terrain::TerrainMod     m_tmod;

    // private functions:

    TerrPanel() {};

    void init();

public:
    static TerrPanel*     getTerrPanel(IGUIWindow* wndw = 0);

    Terrain::TerrainMod*  getTerrainModData()         { return &m_tmod; }
    void                  btnDown(int btn);
    void                  refreshTerrModData();
};

#endif