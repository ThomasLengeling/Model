#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    cubemap[0].load("Barce_Rooftop_C_8k.jpg", 512, true, "filteredMapCache");
    cubemap[1].load("Arches_E_PineTree_8k.jpg", 512, true, "filteredMapCache");
    cubemap[2].load("BasketballCourt_8k.jpg", 512, true, "filteredMapCache");
    ofDisableArbTex();
    
    
    //texturas y normales
    baseColorTex.load("Limon/pulp_COLOR.jpg");
    normalTex.load("Limon/pulp_NRM.jpg");
    
    //modelo
    limonModel.loadModel("Limon/Limon.dae", 20);
    
    limonModel.setRotation(0, 90, 1, 0, 0);
    limonModel.setRotation(1, 270, 0, 0, 1);
    limonModel.setScale(0.9, 0.9, 0.9);
    limonModel.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    
    
    material.baseColor = baseColor;
    material.useBaseColorMap = false;
    material.baseColorMap = &baseColorTex;
    material.useNormalMap = false;
    material.normalMap = &normalTex;
    material.normalVal = normalVal;
    material.textureRepeatTimes = ofVec2f(1.0, 1.0);
    
    baseColor.set("baseColor", ofColor(255), ofColor(0), ofColor(255));
    useBaseColorMap.set("useBaseColorMap", false);
    useNormalMap.set("useNormalMap", false);
    normalVal.set("normalVal", 1.0, 0.0, 1.0);
    environment.set("environment", 0, 0, 2);
    

    gui.setup("IBL");
    gui.add(baseColor);
    gui.add(useBaseColorMap);
    gui.add(useNormalMap);
    gui.add(normalVal);
    gui.add(environment);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    material.baseColor = baseColor;
    material.useBaseColorMap = useBaseColorMap;
    material.useNormalMap = useNormalMap;
    material.normalVal = normalVal;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    cam.begin();
    ibl.begin(&cam, &cubemap[environment]);
    ibl.drawEnvironment(4000.0, 0.2);

    
    material.roughness = 0.5 /9.0;
    material.metallic = 5.0 / 9.0;
    
    material.begin(ibl.getShaderPtr());
    //dibujar el objeto
    for(int i=0; i<limonModel.getNumMeshes(); i++){
        ofPushMatrix();
        ofMultMatrix(limonModel.getMeshHelper(i).matrix);
        
        ofScale(limonModel.getModelMatrix().getScale());
        limonModel.getCurrentAnimatedMesh(i).draw();
        ofPopMatrix();
    }

    material.end();

    ibl.end();
    cam.end();
    ofDisableDepthTest();
   
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
