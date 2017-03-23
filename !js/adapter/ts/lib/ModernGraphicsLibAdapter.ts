import {CModernGraphicsRenderer, CPoint, CRgbaColor} from "./ModernGraphicsLib";
import {ICanvas} from "./GraphicsLib";
import {IOutputStream} from "./OutputStreamLib";

function colorNumberToCRgbaColor(color): CRgbaColor {
    const r = (color >> 16) & 255;
    const g = (color >> 8) & 255;
    const b = color & 255;
    return new CRgbaColor(r / 255.0, g / 255.0,b / 255.0, 1.0)
}

export class CModernGraphicsRendererCanvasObjectAdapter implements ICanvas {
    private m_renderer: CModernGraphicsRenderer;
    private m_lastPoint: CPoint;
    private m_color: CRgbaColor;

    constructor(renderer: CModernGraphicsRenderer) {
        this.m_renderer = renderer;
        this.m_lastPoint = new CPoint(0, 0);
        this.m_color = new CRgbaColor(0.0, 0.0, 0.0, 1.0);
    }

    begin() {
        this.m_renderer.beginDraw();
    }

    end() {
        this.m_renderer.endDraw();
    }

    setColor(color: number) {
        this.m_color = colorNumberToCRgbaColor(color);
    }

    moveTo(x: number, y: number) {
        this.m_lastPoint = new CPoint(x, y);
    }

    lineTo(x: number, y: number) {
        const newPoint = new CPoint(x, y);
        this.m_renderer.drawLine(this.m_lastPoint, newPoint, this.m_color);
        this.m_lastPoint = newPoint;
    }
}

export class CModernGraphicsRendererCanvasClassAdapter extends CModernGraphicsRenderer implements ICanvas {
    private m_lastPoint: CPoint;
    private m_color: CRgbaColor;

    constructor(outputStream: IOutputStream) {
        super(outputStream);
        this.m_lastPoint = new CPoint(0, 0);
        this.m_color = new CRgbaColor(0.0, 0.0, 0.0, 1.0);
    }

    begin() {
        this.beginDraw();
    }

    end() {
        this.endDraw();
    }

    setColor(color: number) {
        this.m_color = colorNumberToCRgbaColor(color);
    }

    moveTo(x: number, y: number) {
        this.m_lastPoint = new CPoint(x, y);
    }

    lineTo(x: number, y: number) {
        const newPoint = new CPoint(x, y);
        this.drawLine(this.m_lastPoint, newPoint, this.m_color);
        this.m_lastPoint = newPoint;
    }
}
