import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: main
    property string text: ""
    property bool readOnly: true

    anchors.fill: parent

    Flickable {
        id: flickable
        property string text: ""
        property bool readOnly: false

        anchors.fill: parent
        TextArea.flickable:
            TextArea {
            id: ta
            readOnly: main.readOnly
            anchors.fill: parent
            text: main.text
            wrapMode: Text.Wrap
            font.bold: true
            font.pointSize: 24


        }
        ScrollBar.vertical: ScrollBar { }
    }
}
