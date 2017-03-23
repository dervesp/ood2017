import {ICanvasDrawable, CTriangle, CRectangle, CCanvasPainter} from "./lib/ShapeDrawingLib";
import {CCanvas} from "./lib/GraphicsLib";
import {CHtmlOutputStream, IOutputStream} from "./lib/OutputStreamLib";
import {CModernGraphicsRendererCanvasObjectAdapter, CModernGraphicsRendererCanvasClassAdapter} from "./lib/ModernGraphicsLibAdapter";
import {CModernGraphicsRenderer} from "./lib/ModernGraphicsLib";

namespace App {
    function PaintPicture(painter: CCanvasPainter) {
        const triangle = new CTriangle([10, 15], [100, 200], [150, 250], 0xFF0080);
        const rectangle = new CRectangle([30, 40], 18, 24);

        painter.draw(triangle);
        painter.draw(rectangle);
    }

    export function PaintPictureOnCanvas(outputStream: IOutputStream) {
        outputStream.print("Paint picture on Canvas:\n");

        const canvas = new CCanvas(outputStream);
        const painter = new CCanvasPainter(canvas);
        PaintPicture(painter);

        outputStream.print("\n");
    }

    export function PaintPictureModernGraphicsRendererObjectAdapter(outputStream: IOutputStream) {
        outputStream.print("Paint picture with ModernGraphicsRendererObjectAdapter:\n");

        const renderer = new CModernGraphicsRenderer(outputStream);
        const canvas = new CModernGraphicsRendererCanvasObjectAdapter(renderer);
        const painter = new CCanvasPainter(canvas);
        PaintPicture(painter);

        outputStream.print("\n");
    }

    export function PaintPictureModernGraphicsRendererClassAdapter(outputStream: IOutputStream) {
        outputStream.print("Paint picture with ModernGraphicsRendererClassAdapter:\n");

        const canvas = new CModernGraphicsRendererCanvasClassAdapter(outputStream);
        const painter = new CCanvasPainter(canvas);
        PaintPicture(painter);

        outputStream.print("\n");
    }
}

const outputStream = new CHtmlOutputStream();
window["cout"] = outputStream;
try {
    App.PaintPictureOnCanvas(outputStream);
    App.PaintPictureModernGraphicsRendererObjectAdapter(outputStream);
    App.PaintPictureModernGraphicsRendererClassAdapter(outputStream);
}
catch (ex) {
    outputStream.print(ex);
    outputStream.print(ex.stack);
}
