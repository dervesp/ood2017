import {ICanvas} from "./GraphicsLib";

export type Point = [number, number];

export interface ICanvasDrawable {
    draw(canvas: ICanvas);
}

abstract class CShape implements ICanvasDrawable {
    private m_color: number;

    constructor(color = 0x000000) {
        this.m_color = color;
    }

    draw(canvas: ICanvas) {
        canvas.setColor(this.m_color);
    }
}

export class CTriangle extends CShape {
    private m_p1: Point;
    private m_p2: Point;
    private m_p3: Point;

    constructor(p1: Point, p2: Point, p3: Point, color = 0x000000) {
        super(color);
        this.m_p1 = p1;
        this.m_p2 = p2;
        this.m_p3 = p3;
    }

    draw(canvas: ICanvas) {
        super.draw(canvas);
        canvas.moveTo(this.m_p1[0], this.m_p1[1]);
        canvas.lineTo(this.m_p2[0], this.m_p2[1]);
        canvas.lineTo(this.m_p3[0], this.m_p3[1]);
        canvas.lineTo(this.m_p1[0], this.m_p1[1]);
    }
}

export class CRectangle extends CShape {
    private m_topLeft: Point;
    private m_bottomRight: Point;

    constructor(topLeft: Point, width: number, height: number, color = 0x000000) {
        super(color);
        this.m_topLeft = topLeft;
        this.m_bottomRight = [topLeft[0] + width, topLeft[1] + height];
    }

    draw(canvas: ICanvas) {
        super.draw(canvas);
        canvas.moveTo(this.m_topLeft[0], this.m_topLeft[1]);
        canvas.lineTo(this.m_bottomRight[0], this.m_topLeft[1]);
        canvas.lineTo(this.m_bottomRight[0], this.m_bottomRight[1]);
        canvas.lineTo(this.m_topLeft[0], this.m_bottomRight[1]);
        canvas.lineTo(this.m_topLeft[0], this.m_topLeft[1]);
    }
}

export class CCanvasPainter {
    private m_canvas: ICanvas;

    constructor(canvas: ICanvas) {
        this.m_canvas = canvas;
    }

    draw(drawable: ICanvasDrawable) {
        this.m_canvas.begin();
        drawable.draw(this.m_canvas);
        this.m_canvas.end();
    }
}