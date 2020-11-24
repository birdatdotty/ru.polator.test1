import QtQuick 2.0
import QtQuick.Controls 2.12

import My 1.0

Rectangle {
    id: rectangle
     color: "aqua"
     property string textPos: ""

     TextPos {
         text: parent.textPos
     }

     LogAreaServer {
         text: qmlNetwork.log1
     }
}
