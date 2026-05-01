import jwt from "jsonwebtoken";

export default function auth(req, res, next) {
    const token = req.headers.authorization?.split(" ")[1];

    if (!token) return res.json({ status:false, message:"Access Denied" });

    try {
        const verified = jwt.verify(token, "SECRET123");
        req.user = verified;
        next();
    } catch {
        res.json({ status:false, message:"Invalid Token" });
    }
}
