#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

		//IMAGE VARIABLES
		ofImage m_Nebula;

		ofImage m_sun;
		ofImage m_mercury;
		ofImage m_venus;
		ofImage m_earth;
		ofImage m_moon;
		ofImage m_mars;
		ofImage m_jupiter;
		ofImage m_saturn;
		ofImage m_uranus;
		ofImage m_neptune;
		ofImage m_pluto;

		ofImage m_spaceShip;
		ofImage m_DestroyerOfWorlds;

		//2D VECTORS
		ofVec2f m_screenCentre;
		ofVec2f m_mercuryPos;
		ofVec2f m_venusPos;
		ofVec2f m_earthPos;
		ofVec2f m_moonPos;
		ofVec2f m_marsPos;
		ofVec2f m_jupiterPos;
		ofVec2f m_saturnPos;
		ofVec2f m_uranusPos;
		ofVec2f m_neptunePos;
		ofVec2f m_plutoPos;

		ofVec2f m_ssPos;
		ofVec2f m_targetSSPos;
		ofVec2f m_DOWPos;
		ofVec2f m_cursorPos;

		//ANGLE FLOATS
		float m_sunAngle;
		float m_mercuryAngle;
		float m_venusAngle;
		float m_earthAngle;
		float m_moonAngle;
		float m_marsAngle;
		float m_jupiterAngle;
		float m_saturnAngle;
		float m_uranusAngle;
		float m_neptuneAngle;
		float m_plutoAngle;

		float m_spaceShipAngle;
		float m_DOWAngle;

		void setup();
		void update();
		void draw();

		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
};
