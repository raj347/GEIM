﻿/** \brief ImagePanel
 *
 * a panel for display image
 * and offer some zoom function to modify the disp-style
 *
 * \file ImagePanel.h
 * \author author:zhd
 * \date date:2014.03.19
 *
 */
#pragma once
#ifndef IMAGEPANEL_H
#define IMAGEPANEL_H

//(*Headers(ImagePanel)
//*)
#include <wx/panel.h>
#include <wx/geometry.h>
#include <wx/dcmemory.h>

enum IMGPL_CMD
{
	NONE,

	IMG_ZIN,
	IMG_ZOUT,
	IMG_ZRECT,
	IMG_ZFIT,
	IMG_ZACTUAL,
	IMG_MOVE,

	SEL_FAINT,
	SEL_MIN,
	SEL_MAX
};

class ImagePanel: public wxPanel
{
public:
	// construct
	ImagePanel();
	ImagePanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& sz=wxDefaultSize);
	virtual ~ImagePanel();

    /** \brief the panel whether contain a ok image
     *
     * \return bool
     *
     */
	bool IsOK() { return m_img.IsOk(); }

	/** \brief set image to dispaly
	 *
	 * \param img wxImage&	[IN] seted image
	 * \return bool			true:success false:failed
	 *
	 */
	bool SetImg(wxImage& img);
	/** \brief destroy image
	 *
	 * \return bool true:success false:failed
	 *
	 */
	bool ReleaseImg();

    /** \brief zoomin image
     *
     * \return bool true:success false:failed
     *
     */
	bool ImgZoomIn();
    /** \brief zoomout image
     *
     * \return bool true:success false:failed
     *
     */
	bool ImgZoomOut();
    /** \brief mouse fuc is sel the display rect
     *
     * \see bool ImgZoomRect(wxRect rcSel)
     * \return bool true:success false:failed
     *
     */
	bool ImgZoomRect();
    /** \brief dispaly image in real size
     *
     * \return bool true:success false:failed
     *
     */
	bool ImgZoomActual();
    /** \brief display image full fit wnd
     *
     * \return bool true:success false:failed
     *
     */
	bool ImgZoomFit();
    /** \brief mouse fuc is move image
     *
     * \see bool ImgMove(wxSize szMove)
     * \return bool true:success false:failed
     *
     */
	bool ImgMove();

    /** \brief select faint spot in image
     *
     * \return bool true:success false:failed
     *
     */
	bool SelFaint();
    /** \brief select min spot in image
     *
     * \return bool true:success false:failed
     *
     */
	bool SelMin();
    /** \brief select max spot in image
     *
     * \return bool true:success false:failed
     *
     */
	bool SelMax();

    /** \brief proc func btn ui update
     *
     * \param IMGPL_CMD cmd					[IN] cmd type
     * \param event wxUpdateUIEvent& [INOUT] event
     * \return bool true:success false:failed
     *
     */
	bool UpdateUI(IMGPL_CMD cmd, wxUpdateUIEvent& event);

protected:

private:
    /** \brief display image of sel rect full fit wnd
     *
     * \param wxRect rc	[IN] rect baseed of wnd
     * \return bool true:success false:failed
     *
     */
	bool ImgZoomRect(wxRect rcSel);
	/** \brief according to the specified zoom percentage
	 *
	 * \param wxDouble dScale              [IN] the specified zoom percentage
	 * \param wxPoint* pPt = nullptr    [IN] the fixed point in wnd coordinate, if nullptr, use the wnd's center
	 * \return bool true:success false:failed
	 *
	 */
	bool ImgZoomScale(wxDouble dScale, wxPoint* pPt = nullptr);
    /** \brief move image
     *
     * \param wxSize szMove	[IN] the size to move in wnd coordinate
     * \return bool true:success false:failed
     *
     */
	bool ImgMove(wxSize szMove);
    /** \brief calculate the rect of the mouse sel
     *
     * \return bool true:success false:failed
     *
     */
	bool RegulaSelRect();


    /** \brief Image Move Mouse event
     *
     * \param event wxMouseEvent& [INOUT] event
     * \return bool true:success false:failed
     *
     */
	bool MLDImgMove(wxMouseEvent& event);
	bool MLUImgMove(wxMouseEvent& event);
	bool MMVImgMove(wxMouseEvent& event);
    /** \brief Image zoom rect mouse event
     *
     * \param event wxMouseEvent& [INOUT] event
     * \return bool true:success false:failed
     *
     */
	bool MLDImgZRect(wxMouseEvent& event);
	bool MLUImgZRect(wxMouseEvent& event);
	bool MMVImgZRect(wxMouseEvent& event);
    /** \brief Select faint spot mouse event
     *
     * \param event wxMouseEvent& [INOUT] event
     * \return bool true:success false:failed
     *
     */
	bool MLDSelFaint(wxMouseEvent& event);
	bool MLUSelFaint(wxMouseEvent& event);
	bool MMVSelFaint(wxMouseEvent& event);
    /** \brief Select min spot mouse event
     *
     * \param event wxMouseEvent& [INOUT] event
     * \return bool true:success false:failed
     *
     */
	bool MLDSelMin(wxMouseEvent& event);
	bool MLUSelMin(wxMouseEvent& event);
	bool MMVSelMin(wxMouseEvent& event);
    /** \brief Select max spot mouse event
     *
     * \param event wxMouseEvent& [INOUT] event
     * \return bool true:success false:failed
     *
     */
	bool MLDSelMax(wxMouseEvent& event);
	bool MLUSelMax(wxMouseEvent& event);
	bool MMVSelMax(wxMouseEvent& event);

    /** \brief stop drag
     *
     * \param true bool bFuc=true [IN] true:remain the fuc false:reset the func
     * \return bool true:success false:failed
     *
     */
	bool EndDrag(bool bFuc = true);

	//(*Handlers(ImagePanel)
	//*)
    /** \brief paint wnd
     *
     * \param event wxPaintEvent&	[INOUT] event
     * \return void
     *
     */
	void OnPaint(wxPaintEvent& event);
    /** \brief erase backgroud
     *
     * \param event wxEraseEvent&
     * \return void
     *
     */
	void OnErase(wxEraseEvent& event);
    /** \brief on wnd resized, do nothing to stop auto erase
     *
     * \param event wxSizeEvent&
     * \return void
     *
     */
	void OnSize(wxSizeEvent& event);
    /** \brief invoke when mouse left button down
     *
     * \param event wxMouseEvent&   [INOUT] the event
     * \return void
     *
     */
	void OnMouseLD(wxMouseEvent& event);
    /** \brief invoke when mouse left button up
     *
     * \param event wxMouseEvent&   [INOUT] the event
     * \return void
     *
     */
	void OnMouseLU(wxMouseEvent& event);
    /** \brief invoke when mouse move
     *
     * \param event wxMouseEvent&   [INOUT] the event
     * \return void
     *
     */
	void OnMouseMove(wxMouseEvent& event);
    /** \brief kill focus. if capture mouse, should release
     *
     * \param event wxFocusEvent&	[INOUT] the event
     * \return void
     *
     */
	void OnKillFocus(wxFocusEvent& event);

	//(*Identifiers(ImagePanel)
	//*)

	//(*Declarations(ImagePanel)
	//*)
	/**< origin iamge, not alter. */
	wxImage m_imgOrigin;
	/**< image to display. */
	wxImage m_img;
	/**< note the old size of the panel, used in calculate locate when size changed */
	wxSize m_szClient = { -1, -1};

	/**< image zoom scale */
	wxDouble m_dScale = 1.0;
	/**< zoom percentage */
	wxDouble m_dScaleDelta = 0.5;
	/**< image rect to draw */
	wxRect2DDouble m_rcSrc = {0.0, 0.0, 0.0, 0.0};
	/**< draw rect on wnd */
	wxRect2DDouble m_rcDest = {0.0, 0.0, 0.0, 0.0};

	/**< memorydc for double buffer draw */
	wxMemoryDC m_dcMem;

    /**< param for mouse */
    struct _ST_MOUSE_PARAM
    {
        /** \brief mouse state flag
         *
         *  0:none 1:LD 2:drag
         *
         */
         wxInt32 iState = 0;
        /** \brief mouse function flag
         *
         *  \see IMGPL_CMD
         *
         */
        IMGPL_CMD emFuc = IMGPL_CMD::NONE;
        /**< start point */
        wxPoint ptB;
        /**< end point */
        wxPoint ptE;

        /**< the regular rect of mouse sel */
        wxRect rcSel;
        /**< the size of mouse move */
        wxSize szMv;

        /**< remain the dest rect before move image */
        wxRect2DDouble rcDO;
        /**< remain the src rect before move iamge */
        wxRect2DDouble rcSO;
    } m_stMP;

	DECLARE_EVENT_TABLE()
};

#endif
