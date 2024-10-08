import React from 'react'
import Title from '../components/Title'
import { assets } from '../assets/assets'
import NewsLetterBox from '../components/NewsLetterBox'

const Contact = () => {
  return (
    <div>
      <div className='text-center text-2xl pt-10 border-t'>
        <Title text1={'CONTACT'} text2={'US'}/>
      </div>
      <div className='my-10 flex flex-col justify-center md:flex-row gap-10 mb:28'>
          <img className='w-full max-w-[480px]' src={assets.contact_img} alt="" />
          <div className='flex flex-col justify-center items-start gap-6'>
              <p className='font-semibold text-xl text-gray-600'>Our store</p>
              <p className='text-gray-500 '>541646 IIITS, Sricity,<br/>CHITTHOR,Andhra Pradesh</p>
              <p className='text-gray-500'>Tel:+91 99xxxxxxxx <br /> admin@makeyourbasket.com</p>
              <p className='font-semibold text-xl text-gray-600'>Creers at your basket</p>
              <p className='text-gray-500 '>Learn about our Teams and job oppotunities</p>
             <button className='border border-black px-8 py-4 text-sm hover:bg-black hover:text-white transition-all duration-500'>Explore Jobs</button>
          </div>
      </div>
      <NewsLetterBox/>
    </div>
  )
}

export default Contact
