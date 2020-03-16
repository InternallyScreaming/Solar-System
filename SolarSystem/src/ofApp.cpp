#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);						//SET FRAMERATE
	ofSetWindowShape(1300, 900);			//SET WINDOW SIZE
	ofSetBackgroundColorHex(0x000000);		//SET BACKGROUND TO BLACK

	//LOAD IMAGE
	m_Nebula.load("Nebula.png");
	
	m_sun.load("sun.png");
	m_mercury.load("mercury.png");
	m_venus.load("venus.png");
	m_earth.load("earth.png");
	m_moon.load("moon.png");
	m_mars.load("mars.png");
	m_jupiter.load("jupiter.png");
	m_saturn.load("saturn.png");
	m_uranus.load("uranus.png");
	m_neptune.load("neptune.png");
	m_pluto.load("pluto.png");

	m_spaceShip.load("spaceShip.png");
	m_DestroyerOfWorlds.load("kanna.png");

	//ROTATION SPEED
	m_sunAngle = 0;
	m_mercuryAngle = 0;
	m_venusAngle = 0;
	m_earthAngle = 0;
	m_moonAngle = 0;
	m_marsAngle = 0;
	m_jupiterAngle = 0;
	m_saturnAngle = 0;
	m_uranusAngle = 0;
	m_neptuneAngle = 0;
	m_plutoAngle = 0;

	m_spaceShipAngle = 0;
	m_DOWAngle = 0;

	//SETTING POSITION
	m_screenCentre = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	m_mercuryPos = ofVec2f(80 * cos(m_mercuryAngle), 100 * sin(m_mercuryAngle));
	m_venusPos = ofVec2f(25+80 * cos(m_venusAngle), 25-60 * sin(m_venusAngle));
	m_earthPos = ofVec2f(0, 200);
	m_moonPos = ofVec2f(0, 175);
	m_marsPos = ofVec2f(220 * cos(m_marsAngle), 200 * sin(m_marsAngle));
	m_jupiterPos = ofVec2f(0, 280);
	m_saturnPos = ofVec2f(0, 310);
	m_uranusPos = ofVec2f(0, 290);
	m_neptunePos = ofVec2f(0, 175);
	m_plutoPos = ofVec2f(520 * cos(m_plutoAngle), 100 * sin(m_plutoAngle));

	m_ssPos = ofVec2f(1250, 850);
	m_targetSSPos = m_ssPos;
	m_DOWPos = ofVec2f(1000, -100);
	m_cursorPos = ofVec2f(0, 0);


	//SETTING ANCHOR POINTS
	m_Nebula.setAnchorPoint(m_Nebula.getWidth() / 2, m_Nebula.getHeight() / 2);

	m_sun.setAnchorPoint(m_sun.getWidth() / 2, m_sun.getHeight() / 2);
	m_mercury.setAnchorPoint(m_mercury.getWidth() / 2, m_mercury.getHeight() / 2);
	m_venus.setAnchorPoint(m_venus.getWidth() / 2, m_venus.getHeight() / 2);
	m_earth.setAnchorPoint(m_earth.getWidth() / 2, m_earth.getHeight() / 2);
	m_moon.setAnchorPoint(m_moon.getWidth() / 2, m_moon.getHeight() / 2);
	m_mars.setAnchorPoint(m_mars.getWidth() / 2, m_mars.getHeight() / 2);
	m_jupiter.setAnchorPoint(m_jupiter.getWidth() / 2, m_jupiter.getHeight() / 2);
	m_saturn.setAnchorPoint(m_saturn.getWidth() / 2, m_saturn.getHeight() / 2);
	m_uranus.setAnchorPoint(m_uranus.getWidth() / 2, m_uranus.getHeight() / 2);
	m_neptune.setAnchorPoint(m_neptune.getWidth() / 2, m_neptune.getHeight() / 2);
	m_pluto.setAnchorPoint(m_pluto.getWidth() / 2, m_pluto.getHeight() / 2);

	m_spaceShip.setAnchorPoint(m_spaceShip.getWidth() / 2, m_spaceShip.getHeight() / 2);
	m_DestroyerOfWorlds.setAnchorPoint(m_DestroyerOfWorlds.getWidth() / 2, m_DestroyerOfWorlds.getHeight() / 2);
}

//--------------------------------------------------------------
void ofApp::update(){

	//REFERENCING THE PROFESSORS CODE
	//CHANGES THE ANGLE OF THE SPACESHIP TO FOLLOW THE MOUSE
	m_cursorPos = ofVec2f(ofGetMouseX(), ofGetMouseY());
	ofVec2f cursorToSS = m_cursorPos - m_ssPos;
	m_spaceShipAngle = (ofRadToDeg(atan2(cursorToSS.x, cursorToSS.y))*-1)-90;

	//CHANGES THE POSITION OF THE SPACESHIP
	m_ssPos.x = ofLerp(m_ssPos.x, m_targetSSPos.x, .02);
	m_ssPos.y = ofLerp(m_ssPos.y, m_targetSSPos.y, .02);

	//INCREMENTING/DECREMENTING THE PLANETARY ORBITS
	m_sunAngle += 0.5;
	m_mercuryAngle -= 1;
	m_venusAngle += 1;
	m_earthAngle += 0.5;
	m_moonAngle += 0.9;
	m_marsAngle -= 1;
	m_jupiterAngle -= 0.2;
	m_saturnAngle += 0.1;
	m_uranusAngle += 0.1;
	m_neptuneAngle += 1;
	m_plutoAngle += 3;
}

//--------------------------------------------------------------
void ofApp::draw(){

	//BACKGROUND
	ofPushMatrix();
		ofTranslate(m_screenCentre);
		m_Nebula.draw(0, 0);
	ofPopMatrix();

	//SUN
	ofPushMatrix();
		ofTranslate(m_screenCentre);

		ofPushMatrix();
			ofRotate(m_sunAngle);
			m_sun.draw(0,0);
		ofPopMatrix();

		ofPushMatrix();
			ofScale(0.75, 0.75);
			ofRotate(m_sunAngle * -1);
			m_sun.draw(0,0);
		ofPopMatrix();

	ofPopMatrix();

	//PLANETS
	ofPushMatrix();
		ofTranslate(m_screenCentre);

		//MERCURY -- PLANET 1
		ofPushMatrix();
			ofTranslate(24, 24);
			ofRotate(m_mercuryAngle);
			ofTranslate(m_mercuryPos);
			ofScale(0.3, 0.3);
			m_mercury.draw(0, 0);
		ofPopMatrix();

		//VENUS -- PLANET 2
		ofPushMatrix();
			ofRotate(180);
			ofTranslate(50, -50);
			ofRotate(m_venusAngle);
			ofTranslate(m_venusPos);
			ofScale(0.4, 0.4);
			m_venus.draw(0, 0);
		ofPopMatrix();

		//EARTH -- PLANET 3
		ofPushMatrix();
			ofRotate(m_earthAngle);
			ofTranslate(m_earthPos);
			ofScale(0.4, 0.4);
			m_earth.draw(0, 0);

			//MOON
			ofScale(0.5, 0.5);
			ofRotate(m_moonAngle);
			m_moon.draw(m_moonPos);

		ofPopMatrix();

		//MARS -- PLANET 4
		ofPushMatrix();
			ofRotate(50);
			ofTranslate(75, 20);
			ofRotate(m_marsAngle);
			ofTranslate(m_marsPos);
			ofScale(0.3, 0.3);
			m_mars.draw(0, 0);
		ofPopMatrix();
		

		//URANUS -- PLANET 5
		ofPushMatrix();
			ofRotate(m_uranusAngle);
			ofTranslate(m_uranusPos);
			ofScale(0.5, 0.5);
			m_uranus.draw(0, 0);

			//NEPTUNE ORBITING URANUS -- PLANET 6
			ofRotate(m_neptuneAngle);
			ofTranslate(m_neptunePos);
			m_neptune.draw(0, 0);
		ofPopMatrix();

		//PLUTO -- PLANET 7
		ofPushMatrix();
			ofRotate(m_plutoAngle);
			ofTranslate(m_plutoPos);
			ofScale(0.4, 0.4);
			m_pluto.draw(0, 0);
		ofPopMatrix();
	ofPopMatrix();

	//SPACESHIP
	ofPushMatrix();
		ofTranslate(m_ssPos);
		ofRotate(m_spaceShipAngle);

		ofPushMatrix();
			ofScale(0.1, 0.1);
			m_spaceShip.draw(0, 0);

			//DESTROYER OF WORLDS
			ofTranslate(m_DOWPos);
			ofScale(2, 2);
			m_DestroyerOfWorlds.draw(0, 0);
		ofPopMatrix();
	ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	m_targetSSPos = ofVec2f(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	m_targetSSPos = ofVec2f(x, y);
}



