//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//

// PropScreen.h: UI for Propeller Geom
// Rob McDonald
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROPSCREEN__INCLUDED_)
#define PROPSCREEN__INCLUDED_

#include "ScreenBase.h"
#include "GuiDevice.h"
#include "GroupLayout.h"

#include <FL/Fl.H>

class PropScreen : public GeomScreen
{
public:
    PropScreen( ScreenMgr* mgr );
    virtual ~PropScreen();

    virtual void Show();
    virtual bool Update();

    virtual void CallBack( Fl_Widget *w );
    virtual void GuiDeviceCallBack( GuiDevice* d );

    virtual void RebuildCSTGroup( CSTAirfoil* cst_xs );

protected:

    enum { CHORD, TWIST, RAKE, SKEW, SWEEP, AXIAL, TANGENTIAL, THICK, CLI };

    GroupLayout m_DesignLayout;

    SliderAdjRangeInput m_PropDiameterSlider;

    SliderAdjRangeInput m_NBladeSlider;

    SliderAdjRangeInput m_PropRotateSlider;
    SliderAdjRangeInput m_Beta34Slider;
    SliderAdjRangeInput m_FeatherSlider;
    SliderAdjRangeInput m_PreconeSlider;

    ToggleButton m_Beta34Toggle;
    ToggleButton m_FeatherToggle;
    ToggleRadioGroup m_BetaToggle;

    SliderAdjRangeInput m_ConstructSlider;
    SliderAdjRangeInput m_FeatherOffsetSlider;
    SliderAdjRangeInput m_FeatherAxisSlider;

    ToggleButton m_ReverseToggle;

    SliderAdjRangeInput m_AFLimitSlider;
    Output m_AFOutput;
    Output m_CLiOutput;
    Output m_SolidityOutput;
    Output m_TSolidityOutput;
    Output m_PSolidityOutput;
    Output m_ChordOutput;
    Output m_TChordOutput;
    Output m_PChordOutput;

    Choice m_PropModeChoice;

    GroupLayout m_XSecLayout;

    IndexSelector m_XSecIndexSelector;

    TriggerButton m_InsertXSec;
    TriggerButton m_CutXSec;
    TriggerButton m_CopyXSec;
    TriggerButton m_PasteXSec;

    FractParmSlider m_XSecRadSlider;

    Choice m_XSecTypeChoice;
    TriggerButton m_ShowXSecButton;

    TriggerButton m_ConvertCEDITButton;
    GroupLayout m_ConvertCEDITGroup;

    GroupLayout m_EditCEDITGroup;
    TriggerButton m_EditCEDITButton;

    GroupLayout m_PointGroup;

    GroupLayout m_SuperGroup;
    SliderAdjRangeInput m_SuperHeightSlider;
    SliderAdjRangeInput m_SuperWidthSlider;
    SliderAdjRangeInput m_SuperMSlider;
    SliderAdjRangeInput m_SuperNSlider;
    ToggleButton m_SuperToggleSym;
    SliderAdjRangeInput m_SuperM_botSlider;
    SliderAdjRangeInput m_SuperN_botSlider;
    SliderAdjRangeInput m_SuperMaxWidthLocSlider;

    GroupLayout m_CircleGroup;
    SliderAdjRangeInput m_DiameterSlider;

    GroupLayout m_EllipseGroup;
    SliderAdjRangeInput m_EllipseHeightSlider;
    SliderAdjRangeInput m_EllipseWidthSlider;

    GroupLayout m_RoundedRectGroup;
    SliderAdjRangeInput m_RRHeightSlider;
    SliderAdjRangeInput m_RRWidthSlider;
    ToggleButton m_RRRadNoSymToggle;
    ToggleButton m_RRRadRLSymToggle;
    ToggleButton m_RRRadTBSymToggle;
    ToggleButton m_RRRadAllSymToggle;
    ToggleRadioGroup m_RRRadSymRadioGroup;
    SliderAdjRangeInput m_RRRadiusBRSlider; // Bottom Right
    SliderAdjRangeInput m_RRRadiusBLSlider; // Bottom Left
    SliderAdjRangeInput m_RRRadiusTLSlider; // Top Left
    SliderAdjRangeInput m_RRRadiusTRSlider; // Top Right
    ToggleButton m_RRKeyCornerButton;
    SliderAdjRangeInput m_RRSkewSlider;
    SliderAdjRangeInput m_RRKeystoneSlider;
    SliderAdjRangeInput m_RRVSkewSlider;

    GroupLayout m_GenGroup;
    SliderAdjRangeInput m_GenHeightSlider;
    SliderAdjRangeInput m_GenWidthSlider;
    SliderAdjRangeInput m_GenMaxWidthLocSlider;
    SliderAdjRangeInput m_GenCornerRadSlider;
    SliderAdjRangeInput m_GenTopTanAngleSlider;
    SliderAdjRangeInput m_GenBotTanAngleSlider;
    SliderAdjRangeInput m_GenTopStrSlider;
    SliderAdjRangeInput m_GenBotStrSlider;
    SliderAdjRangeInput m_GenUpStrSlider;
    SliderAdjRangeInput m_GenLowStrSlider;

    GroupLayout m_FourSeriesGroup;
    StringOutput m_FourNameOutput;
    CheckButton m_FourInvertButton;
    SliderAdjRangeInput m_FourChordSlider;
    SliderAdjRangeInput m_FourThickChordSlider;
    SliderAdjRangeInput m_FourCamberSlider;
    SliderAdjRangeInput m_FourCLiSlider;
    ToggleButton m_FourCamberButton;
    ToggleButton m_FourCLiButton;
    ToggleRadioGroup m_FourCamberGroup;
    SliderAdjRangeInput m_FourCamberLocSlider;
    CheckButton m_FourSharpTEButton;

    TriggerButton m_FourFitCSTButton;
    Counter m_FourDegreeCounter;

    GroupLayout m_SixSeriesGroup;
    StringOutput m_SixNameOutput;
    CheckButton m_SixInvertButton;
    Choice m_SixSeriesChoice;
    SliderAdjRangeInput m_SixChordSlider;
    SliderAdjRangeInput m_SixThickChordSlider;
    SliderAdjRangeInput m_SixIdealClSlider;
    SliderAdjRangeInput m_SixASlider;

    TriggerButton m_SixFitCSTButton;
    Counter m_SixDegreeCounter;

    GroupLayout m_BiconvexGroup;
    SliderAdjRangeInput m_BiconvexChordSlider;
    SliderAdjRangeInput m_BiconvexThickChordSlider;

    GroupLayout m_WedgeGroup;
    SliderAdjRangeInput m_WedgeChordSlider;
    SliderAdjRangeInput m_WedgeThickChordSlider;
    SliderAdjRangeInput m_WedgeZCamberSlider;
    ToggleButton m_WedgeSymmThickButton;
    SliderAdjRangeInput m_WedgeThickLocSlider;
    SliderAdjRangeInput m_WedgeThickLocLowSlider;
    SliderAdjRangeInput m_WedgeFlatUpSlider;
    SliderAdjRangeInput m_WedgeFlatLowSlider;
    SliderAdjRangeInput m_WedgeUForeUpSlider;
    SliderAdjRangeInput m_WedgeUForeLowSlider;
    SliderAdjRangeInput m_WedgeDuUpSlider;
    SliderAdjRangeInput m_WedgeDuLowSlider;

    GroupLayout m_FuseFileGroup;
    TriggerButton m_ReadFuseFileButton;
    SliderAdjRangeInput m_FileHeightSlider;
    SliderAdjRangeInput m_FileWidthSlider;

    GroupLayout m_AfFileGroup;
    TriggerButton m_AfReadFileButton;
    StringOutput m_AfFileNameOutput;
    CheckButton m_AfFileInvertButton;
    SliderAdjRangeInput m_AfFileChordSlider;
    SliderAdjRangeInput m_AfFileThickChordSlider;
    Output m_AfFileBaseThickChordOutput;

    TriggerButton m_AfFileFitCSTButton;
    Counter m_AfFileDegreeCounter;

    GroupLayout m_CSTAirfoilGroup;

    TriggerButton m_UpDemoteButton;
    StringOutput m_UpDegreeOutput;
    TriggerButton m_UpPromoteButton;

    Fl_Scroll* m_CSTUpCoeffScroll;
    GroupLayout m_CSTUpCoeffLayout;

    TriggerButton m_LowDemoteButton;
    StringOutput m_LowDegreeOutput;
    TriggerButton m_LowPromoteButton;

    vector < SliderAdjRangeInput > m_UpCoeffSliderVec;

    Fl_Scroll* m_CSTLowCoeffScroll;
    GroupLayout m_CSTLowCoeffLayout;

    vector < SliderAdjRangeInput > m_LowCoeffSliderVec;

    CheckButton m_CSTInvertButton;
    CheckButton m_CSTContLERadButton;

    GroupLayout m_VKTGroup;
    SliderAdjRangeInput m_VKTChordSlider;
    SliderAdjRangeInput m_VKTEpsilonSlider;
    SliderAdjRangeInput m_VKTKappaSlider;
    SliderAdjRangeInput m_VKTTauSlider;
    CheckButton m_VKTInvertButton;

    TriggerButton m_VKTFitCSTButton;
    Counter m_VKTDegreeCounter;

    GroupLayout m_FourDigitModGroup;
    StringOutput m_FourModNameOutput;
    CheckButton m_FourModInvertButton;
    SliderAdjRangeInput m_FourModChordSlider;
    SliderAdjRangeInput m_FourModThickChordSlider;
    SliderAdjRangeInput m_FourModCamberSlider;
    SliderAdjRangeInput m_FourModCLiSlider;
    ToggleButton m_FourModCamberButton;
    ToggleButton m_FourModCLiButton;
    ToggleRadioGroup m_FourModCamberGroup;
    SliderAdjRangeInput m_FourModCamberLocSlider;
    SliderAdjRangeInput m_FourModThicknessLocSlider;
    SliderAdjRangeInput m_FourModLERadIndexSlider;
    CheckButton m_FourModSharpTEButton;

    TriggerButton m_FourModFitCSTButton;
    Counter m_FourModDegreeCounter;

    GroupLayout m_FiveDigitGroup;
    StringOutput m_FiveNameOutput;
    CheckButton m_FiveInvertButton;
    SliderAdjRangeInput m_FiveChordSlider;
    SliderAdjRangeInput m_FiveThickChordSlider;
    SliderAdjRangeInput m_FiveCLiSlider;
    SliderAdjRangeInput m_FiveCamberLocSlider;
    CheckButton m_FiveSharpTEButton;

    TriggerButton m_FiveFitCSTButton;
    Counter m_FiveDegreeCounter;

    GroupLayout m_FiveDigitModGroup;
    StringOutput m_FiveModNameOutput;
    CheckButton m_FiveModInvertButton;
    SliderAdjRangeInput m_FiveModChordSlider;
    SliderAdjRangeInput m_FiveModThickChordSlider;
    SliderAdjRangeInput m_FiveModCLiSlider;
    SliderAdjRangeInput m_FiveModCamberLocSlider;
    SliderAdjRangeInput m_FiveModThicknessLocSlider;
    SliderAdjRangeInput m_FiveModLERadIndexSlider;
    CheckButton m_FiveModSharpTEButton;

    TriggerButton m_FiveModFitCSTButton;
    Counter m_FiveModDegreeCounter;

    GroupLayout m_OneSixSeriesGroup;
    StringOutput m_OneSixSeriesNameOutput;
    CheckButton m_OneSixSeriesInvertButton;
    SliderAdjRangeInput m_OneSixSeriesChordSlider;
    SliderAdjRangeInput m_OneSixSeriesThickChordSlider;
    SliderAdjRangeInput m_OneSixSeriesCLiSlider;
    SliderAdjRangeInput m_OneSixSeriesCamberLocSlider;
    SliderAdjRangeInput m_OneSixSeriesThicknessLocSlider;
    SliderAdjRangeInput m_OneSixSeriesLERadIndexSlider;
    CheckButton m_OneSixSeriesSharpTEButton;

    TriggerButton m_OneSixSeriesFitCSTButton;
    Counter m_OneSixSeriesDegreeCounter;

    // Overall planform tab
    GroupLayout m_ModifyLayout;

    IndexSelector m_XSecModIndexSelector;

    Choice m_TECloseChoice;
    ToggleButton m_TECloseABSButton;
    ToggleButton m_TECloseRELButton;
    ToggleRadioGroup m_TECloseGroup;

    SliderAdjRange2Input m_CloseTEThickSlider;

    Choice m_TETrimChoice;
    ToggleButton m_TETrimABSButton;
    ToggleButton m_TETrimRELButton;
    ToggleRadioGroup m_TETrimGroup;

    SliderAdjRange2Input m_TrimTEXSlider;
    SliderAdjRange2Input m_TrimTEThickSlider;

    Choice m_TECapChoice;
    SliderAdjRangeInput m_TECapLengthSlider;
    SliderAdjRangeInput m_TECapOffsetSlider;
    SliderAdjRangeInput m_TECapStrengthSlider;

    Choice m_LECloseChoice;
    ToggleButton m_LECloseABSButton;
    ToggleButton m_LECloseRELButton;
    ToggleRadioGroup m_LECloseGroup;

    SliderAdjRange2Input m_CloseLEThickSlider;

    Choice m_LETrimChoice;
    ToggleButton m_LETrimABSButton;
    ToggleButton m_LETrimRELButton;
    ToggleRadioGroup m_LETrimGroup;

    SliderAdjRange2Input m_TrimLEXSlider;
    SliderAdjRange2Input m_TrimLEThickSlider;

    Choice m_LECapChoice;
    SliderAdjRangeInput m_LECapLengthSlider;
    SliderAdjRangeInput m_LECapOffsetSlider;
    SliderAdjRangeInput m_LECapStrengthSlider;

    SliderAdjRangeInput m_AFThetaSlider;
    SliderAdjRangeInput m_AFScaleSlider;
    SliderAdjRangeInput m_AFDeltaXSlider;
    SliderAdjRangeInput m_AFDeltaYSlider;
    SliderAdjRangeInput m_AFShiftLESlider;


    GroupLayout* m_CurrDisplayGroup;
    void DisplayGroup( GroupLayout* group );


    GroupLayout m_BladeLayout;

    Choice m_CurveChoice;
    int m_EditCurve;

    PCurveEditor m_CurveEditor;

    GroupLayout m_MoreLayout;

    SliderAdjRangeInput m_RFoldSlider;
    SliderAdjRangeInput m_AxFoldSlider;
    SliderAdjRangeInput m_OffFoldSlider;
    SliderAdjRangeInput m_AzFoldSlider;
    SliderAdjRangeInput m_ElFoldSlider;
    SliderAdjRangeInput m_FoldAngleSlider;

    Choice m_RootCapTypeChoice;
    SliderAdjRangeInput m_RootCapLenSlider;
    SliderAdjRangeInput m_RootCapOffsetSlider;
    SliderAdjRangeInput m_RootCapStrengthSlider;
    ToggleButton m_RootCapSweepFlagButton;

    Choice m_TipCapTypeChoice;
    SliderAdjRangeInput m_TipCapLenSlider;
    SliderAdjRangeInput m_TipCapOffsetSlider;
    SliderAdjRangeInput m_TipCapStrengthSlider;
    ToggleButton m_TipCapSweepFlagButton;

    SliderAdjRangeInput m_CapTessSlider;

    SliderAdjRangeInput m_LEClusterSlider;
    SliderAdjRangeInput m_TEClusterSlider;
    SliderAdjRangeInput m_RootClusterSlider;
    SliderAdjRangeInput m_TipClusterSlider;
    Output m_SmallPanelWOutput;
    Output m_MaxGrowthOutput;

};


#endif // !defined(PROPSCREEN__INCLUDED_)
