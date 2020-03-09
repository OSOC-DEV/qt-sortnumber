import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Sorter")
    signal submitTextField(string text)
    function setTextField(text){
        console.log("setTextField: " + text)
        stringInput.text = text
    }
    function activateClicked() {
        print(stringInput.text)
        submitTextField(stringInput.text)
    }

    Button {
        id: activate
        x: 250
        y: 187
        text: qsTr("Activate")
        anchors.horizontalCenterOffset: 0
        anchors.verticalCenterOffset: 30
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        checkable: false
        checked: false
        highlighted: false
        flat: true
    }

    TextField {
        id: stringInput
        x: 209
        y: 221
        text: qsTr("")
        anchors.verticalCenterOffset: -24
        anchors.horizontalCenterOffset: 0
        horizontalAlignment: Text.AlignHCenter
        placeholderText: "Enter an array of strings"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Connections {
        target: activate
        onClicked: activateClicked()
    }
}
