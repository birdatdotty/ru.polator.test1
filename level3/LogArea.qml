import QtQuick 2.0
import QtQuick.Controls 2.12

import My 1.0

Item {
    id: main
    property string text: ""
    property bool readOnly: false
    property QmlUser user: qmlUser1

    anchors.fill: parent

    Flickable {
    id: flickable
    property string text: ""
    property bool readOnly: false

    anchors.fill: parent
    TextArea.flickable:
        TextArea {
        id: ta
        readOnly: flickable.readOnly
        anchors.fill: parent
        text: user.log
        wrapMode: Text.Wrap
        font.bold: true
        font.pointSize: 16


    }
    ScrollBar.vertical: ScrollBar { }
}
    TextInput {
        id: myInput
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
        text: main.user.status
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

//            EnterKeyAction.enabled: myInput.text.length > 0 || myInput.inputMethodComposing
//            EnterKeyAction.label: "Next"
        Keys.onReleased: {
            if (event.key === Qt.Key_Return) {
                main.user.enter(myInput.text)
            }
        }
    }

}
