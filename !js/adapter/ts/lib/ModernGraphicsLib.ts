import {IOutputStream} from "./OutputStreamLib";

export class CPoint {
    private m_x: number;
    private m_y: number;
    constructor(x: number, y: number) {
        this.m_x = x;
        this.m_y = y;
    }

    x(): number {
        return this.m_x;
    }

    y(): number {
        return this.m_y;
    }
}

export class CRgbaColor {
    private m_r: number;
    private m_g: number;
    private m_b: number;
    private m_a: number;

    constructor(r: number, g: number, b: number, a: number) {
        const normalizeFunc = (num: number) => Math.min(Math.max(0, num), 1);
        this.m_r = normalizeFunc(r);
        this.m_g = normalizeFunc(g);
        this.m_b = normalizeFunc(b);
        this.m_a = normalizeFunc(a);
    }

    r(): number {
        return this.m_r;
    }

    g(): number {
        return this.m_g;
    }

    b(): number {
        return this.m_b;
    }

    a(): number {
        return this.m_a;
    }
}

export class CModernGraphicsRenderer {
    m_out: IOutputStream;
    m_drawing: boolean;
    constructor(outputStream: IOutputStream) {
        this.m_out = outputStream;
        this.m_drawing = false;
    }

    beginDraw() {
        if (this.m_drawing) {
            throw new Error("Drawing has already begun");
        }
        this.m_out.print(`<draw>\n`);
        this.m_drawing = true;
    }

    drawLine(p1: CPoint, p2: CPoint, c: CRgbaColor) {
        if (!this.m_drawing) {
            throw new Error("DrawLine is allowed between BeginDraw()/EndDraw() only");
        }
        this.m_out.print(`  <line fromX="${p1.x()}" fromY="${p1.y()}" toX="${p2.x()}" toY="${p2.y()}">\n`);
        this.m_out.print(`    <color r="${c.r()}" g="${c.g()}" b="${c.b()}" a="${c.a()}">\n`);
        this.m_out.print(`  </line>\n`);
    }

    endDraw() {
        if (!this.m_drawing) {
            throw new Error("Drawing has not been started");
        }
        this.m_out.print(`</draw>\n`);
        this.m_drawing = false;
    }
}