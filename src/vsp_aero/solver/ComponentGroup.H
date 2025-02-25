//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//
//////////////////////////////////////////////////////////////////////

#ifndef COMPONENT_GROUP_H
#define COMPONENT_GROUP_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "utils.H"
#include "quat.H"
#include "matrix.H"
#include "WOPWOP.H"
#include "SpanLoadRotorData.H"

#define STEADY_RATES   1
#define PERIODIC_RATES 2
#define FULL_DYNAMIC   3

class COMPONENT_GROUP {

private:

    char GroupName_[2000];
    
    int NumberOfComponents_;
    int *ComponentList_;
    
    int GeometryIsFixed_;
    int GeometryIsDynamic_;
    int GeometryIsARotor_;
    int GeometryHasWings_;
    int GeometryHasBodies_;
    
    WOPWOP WopWop_;
    
    VSPAERO_DOUBLE OVec_[3];
    VSPAERO_DOUBLE RVec_[3];
    VSPAERO_DOUBLE TVec_[3];
    
    VSPAERO_DOUBLE UserInputVelocity_[3];
    VSPAERO_DOUBLE UserInputAcceleration_[3];

    VSPAERO_DOUBLE Mass_;
    VSPAERO_DOUBLE Ixx_;
    VSPAERO_DOUBLE Iyy_;
    VSPAERO_DOUBLE Izz_;
    VSPAERO_DOUBLE Ixy_;
    VSPAERO_DOUBLE Ixz_;
    VSPAERO_DOUBLE Iyz_;
    VSPAERO_DOUBLE Omega_;
    VSPAERO_DOUBLE Angle_;
    VSPAERO_DOUBLE TimeStep_;
    VSPAERO_DOUBLE CurrentTime_;
    VSPAERO_DOUBLE RotorDiameter_;
    VSPAERO_DOUBLE AngleMax_;
    VSPAERO_DOUBLE TotalRotationAngle_;
    VSPAERO_DOUBLE StartDynamicAnalysisTime_;
    
    // Integrated forces
    
    int NumberOfTimeSamples_;
    
    int StartAveragingTimeStep_;
    VSPAERO_DOUBLE StartAveragingTime_;

    VSPAERO_DOUBLE Cxo_[2];
    VSPAERO_DOUBLE Cyo_[2];
    VSPAERO_DOUBLE Czo_[2];
    
    VSPAERO_DOUBLE Cx_[2];
    VSPAERO_DOUBLE Cy_[2];
    VSPAERO_DOUBLE Cz_[2];

    VSPAERO_DOUBLE Cmxo_[2];
    VSPAERO_DOUBLE Cmyo_[2];
    VSPAERO_DOUBLE Cmzo_[2];

    VSPAERO_DOUBLE Cmx_[2];
    VSPAERO_DOUBLE Cmy_[2];
    VSPAERO_DOUBLE Cmz_[2];

    VSPAERO_DOUBLE CL_[2];
    VSPAERO_DOUBLE CD_[2];
    VSPAERO_DOUBLE CS_[2];

    VSPAERO_DOUBLE CLo_[2];
    VSPAERO_DOUBLE CDo_[2];
    VSPAERO_DOUBLE CSo_[2];
    
    // Free stream conditions
    
    VSPAERO_DOUBLE Density_;
    VSPAERO_DOUBLE Vref_;
    VSPAERO_DOUBLE Sref_;
    VSPAERO_DOUBLE Bref_;  
    VSPAERO_DOUBLE Cref_;  
    
    // Spanwise forces and moments, for wings and rotors
    
    int NumberOfLiftingSurfaces_;
    
    SPAN_LOAD_ROTOR_DATA *SpanLoadData_;
    
    MATRIX MassMatrix_;
    MATRIX InertiaMatrix_;
    MATRIX InertiaMatrixInverse_;
    MATRIX RotationMatrix_;
    MATRIX RotationMatrixInverse_;
    MATRIX OmegaDot_;
    MATRIX LinearMomentum_;
    MATRIX AngularMomentum_;
    MATRIX XDot_;
    MATRIX VDot_;
    MATRIX Velocity_;
    MATRIX Acceleration_;
        
    QUAT TotalQuat_; // Total quat ... full rotation over all time
    QUAT Quat_;      // Current quat, just rotation over current time step
    QUAT InvQuat_;   // Inverse of current quat
    QUAT WQuat_;     // Rate derivative of current quat, for velocities
    
    void UpdateSteadyRates(void);
    void UpdatePeriodicRates(void);
    void UpdateDynamicSystem(void);
    
    void QuatToMatrix(QUAT &Quat, MATRIX &Matrix, MATRIX &Inverse);
    
public:

    COMPONENT_GROUP(void);
   ~COMPONENT_GROUP(void);
    COMPONENT_GROUP(const COMPONENT_GROUP &ComponentGroup);

    COMPONENT_GROUP& operator=(const COMPONENT_GROUP &ComponentGroup);
    
    char *GroupName(void) { return GroupName_; };

    int NumberOfComponents(void) { return NumberOfComponents_; };
    
    int &ComponentList(int i) { return ComponentList_[i]; };

    int &GeometryIsFixed(void) { return GeometryIsFixed_; };
    
    int &GeometryIsDynamic(void) { return GeometryIsDynamic_; };
    
    int &GeometryIsARotor(void) { return GeometryIsARotor_; };
    
    int &GeometryHasWings(void) { return GeometryHasWings_; };
    
    int &GeometryHasBodies(void) { return GeometryHasBodies_; };

    WOPWOP &WopWop(void) { return WopWop_; };
    
    VSPAERO_DOUBLE &RotorDiameter(void) { return RotorDiameter_; };
    
    VSPAERO_DOUBLE &AngleMax(void) { return AngleMax_; };
    
    // Integrated forces and moments
    
    VSPAERO_DOUBLE &Cxo(void) { return Cxo_[0]; };
    VSPAERO_DOUBLE &Cyo(void) { return Cyo_[0]; };
    VSPAERO_DOUBLE &Czo(void) { return Czo_[0]; };
        
    VSPAERO_DOUBLE &Cx(void) { return Cx_[0]; };
    VSPAERO_DOUBLE &Cy(void) { return Cy_[0]; };
    VSPAERO_DOUBLE &Cz(void) { return Cz_[0]; };

    VSPAERO_DOUBLE &Cmxo(void) { return Cmxo_[0]; };
    VSPAERO_DOUBLE &Cmyo(void) { return Cmyo_[0]; };
    VSPAERO_DOUBLE &Cmzo(void) { return Cmzo_[0]; };
    
    VSPAERO_DOUBLE &Cmx(void) { return Cmx_[0]; };
    VSPAERO_DOUBLE &Cmy(void) { return Cmy_[0]; };
    VSPAERO_DOUBLE &Cmz(void) { return Cmz_[0]; };

    VSPAERO_DOUBLE &CLo(void) { return CLo_[0]; };
    VSPAERO_DOUBLE &CDo(void) { return CDo_[0]; };
    VSPAERO_DOUBLE &CSo(void) { return CSo_[0]; };        

    VSPAERO_DOUBLE &CL(void) { return CL_[0]; };
    VSPAERO_DOUBLE &CD(void) { return CD_[0]; };
    VSPAERO_DOUBLE &CS(void) { return CS_[0]; };
        
    // Average integrated forces and moments
    
    VSPAERO_DOUBLE &CxoAvg(void) { return Cxo_[1]; };
    VSPAERO_DOUBLE &CyoAvg(void) { return Cyo_[1]; };
    VSPAERO_DOUBLE &CzoAvg(void) { return Czo_[1]; };
    
    VSPAERO_DOUBLE &CxAvg(void) { return Cx_[1]; };
    VSPAERO_DOUBLE &CyAvg(void) { return Cy_[1]; };
    VSPAERO_DOUBLE &CzAvg(void) { return Cz_[1]; };

    VSPAERO_DOUBLE &CmxoAvg(void) { return Cmxo_[1]; };
    VSPAERO_DOUBLE &CmyoAvg(void) { return Cmyo_[1]; };
    VSPAERO_DOUBLE &CmzoAvg(void) { return Cmzo_[1]; };
    
    VSPAERO_DOUBLE &CmxAvg(void) { return Cmx_[1]; };
    VSPAERO_DOUBLE &CmyAvg(void) { return Cmy_[1]; };
    VSPAERO_DOUBLE &CmzAvg(void) { return Cmz_[1]; };

    VSPAERO_DOUBLE &CLoAvg(void) { return CLo_[1]; };
    VSPAERO_DOUBLE &CDoAvg(void) { return CDo_[1]; };
    VSPAERO_DOUBLE &CSoAvg(void) { return CSo_[1]; };      

    VSPAERO_DOUBLE &CLAvg(void) { return CL_[1]; };
    VSPAERO_DOUBLE &CDAvg(void) { return CD_[1]; };
    VSPAERO_DOUBLE &CSAvg(void) { return CS_[1]; };
        
    VSPAERO_DOUBLE &StartAveragingTime(void) { return StartAveragingTime_; };
    
    void ZeroAverageForcesAndMoments(void);
    void UpdateAverageForcesAndMoments(void);
    void CalculateAverageForcesAndMoments(void);

    // Free stream conditions
    
    VSPAERO_DOUBLE &Density(void) { return Density_; };
    VSPAERO_DOUBLE &Vref(void) { return Vref_; };
    VSPAERO_DOUBLE &Sref(void) { return Sref_; };
    VSPAERO_DOUBLE &Bref(void) { return Bref_; };
    VSPAERO_DOUBLE &Cref(void) { return Cref_; };    
        
    // Spanwise forces and moments, for wings and rotors
    
    void SizeSpanLoadingList(int NumberOfLiftingSurfaces);
    
    int NumberOfLiftingSurfaces(void) { return NumberOfLiftingSurfaces_; };
    
    SPAN_LOAD_ROTOR_DATA &SpanLoadData(int i) { return SpanLoadData_[i]; };
    
    // Geometry, orientation, rotation information
        
    VSPAERO_DOUBLE &OVec(int i) { return OVec_[i]; };
    VSPAERO_DOUBLE *OVec(void) { return OVec_; };

    VSPAERO_DOUBLE &RVec(int i) { return RVec_[i]; };
    VSPAERO_DOUBLE *RVec(void) { return RVec_; };

    VSPAERO_DOUBLE TVec(int i) { return TVec_[i]; };
    
    VSPAERO_DOUBLE &Velocity(int i ) { return Velocity_(i+1); };
        
    VSPAERO_DOUBLE &Omega(void) { return Omega_; };   
    
    VSPAERO_DOUBLE Period(void) { return ABS(2.*PI/Omega_); };
    
    VSPAERO_DOUBLE &TotalRotationAngle(void) { return TotalRotationAngle_; };
        
    VSPAERO_DOUBLE Angle(void) { return Angle_; }; 
       
    QUAT &Quat(void) { return Quat_; };
    QUAT &InvQuat(void) { return InvQuat_; };
    QUAT &WQuat(void) { return WQuat_; };
    
    void SizeList(int NumberOfComponents);

    void Update(VSPAERO_DOUBLE TimeStep, VSPAERO_DOUBLE CurrentTime);
    
    void WriteData(FILE *File);
    void LoadData(FILE *File);

};

#endif
