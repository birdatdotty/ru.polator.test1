import QtQuick 2.0

import My 1.0

Rectangle {
    id: rectangle
    property string textPos: ""
    property QmlUser user: qmlUser1
    color: "aquamarine"

    TextPos {
        text: parent.textPos
    }
    LogArea {
//        text: ""
        user: rectangle.user
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
    }

}
