import { Link } from 'react-router-dom'

export default function Contact() {
	return (
		<div className="container">
			<div className="m-3">
				<h3 className="text-primary">Contact Us:-</h3>
				<p>If you have any inquiries or need assistance, please feel free to contact us using the information below:</p>
			</div>
			<div className="m-3">
				<h4 className="text-primary">Contact Information:-</h4>
				<p><strong>Address:</strong> 123 Movie Lane, Film City, CA 90210</p>
				<p><strong>Email:</strong> support@bookamovie.com</p>
				<p><strong>Phone:</strong> 123-456-7890</p>
			</div>
			<div className="m-3">
				<h4 className="text-primary">Customer Support Hours:-</h4>
				<p>Our customer support team is available to assist you during the following hours:</p>
				<p><strong>Monday - Friday:</strong> 9:00 AM - 6:00 PM</p>
				<p><strong>Saturday:</strong> 10:00 AM - 4:00 PM</p>
				<p><strong>Sunday:</strong> Closed</p>
			</div>
			<div className="m-3">
				<h4 className="text-primary">Follow Us:-</h4>
				<p>Stay connected with us on social media:</p>
				<p><Link to="#" target="_blank">Facebook</Link> | <Link to="#" target="_blank">Twitter</Link> | <Link to="#" target="_blank">Instagram</Link></p>
			</div>
		</div>
	)
}