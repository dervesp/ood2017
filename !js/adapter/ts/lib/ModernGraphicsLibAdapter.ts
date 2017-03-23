import {CModernGraphicsRenderer, CPoint} from "./ModernGraphicsLib";
import {ICanvas} from "./GraphicsLib";
import {IOutputStream} from "./OutputStreamLib";

export class CModernGraphicsRendererCanvasObjectAdapter implements ICanvas {
    private m_renderer: CModernGraphicsRenderer;
    private m_lastPoint: CPoint;

    constructor(renderer: CModernGraphicsRenderer) {
        this.m_renderer = renderer;
        this.m_lastPoint = new CPoint(0, 0);
    }

    begin() {
        this.m_renderer.beginDraw();
    }

    end() {
        this.m_renderer.endDraw();
    }

    moveTo(x: number, y: number) {
        this.m_lastPoint = new CPoint(x, y);
    }

    lineTo(x: number, y: number) {
        const newPoint = new CPoint(x, y);
        this.m_renderer.drawLine(this.m_lastPoint, newPoint);
        this.m_lastPoint = newPoint;
    }
}

export class CModernGraphicsRendererCanvasClassAdapter extends CModernGraphicsRenderer implements ICanvas {
    private m_lastPoint: CPoint;

    constructor(outputStream: IOutputStream) {
        super(outputStream);
    }

    begin() {
        this.beginDraw();
    }

    end() {
        this.endDraw();
    }

    moveTo(x: number, y: number) {
        this.m_lastPoint = new CPoint(x, y);
    }

    lineTo(x: number, y: number) {
        const newPoint = new CPoint(x, y);
        this.drawLine(this.m_lastPoint, newPoint);
        this.m_lastPoint = newPoint;
    }
}
